#include <iostream>
#include <string>
#include <iomanip>

class SavingsAccount {
    std::string accountNumber;
    double balance;
    double transactions[10];
    int count;
    int head;

public:
    SavingsAccount(std::string accNo, double initialBalance)
        : accountNumber(accNo), balance(initialBalance), count(0), head(0) {
        for(int i=0; i<10; ++i) transactions[i] = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        transactions[head] = amount;
        head = (head + 1) % 10;
        if (count < 10) count++;
        std::cout << "Deposited: " << amount << ". New Balance: " << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient funds for withdrawal of " << amount << "\n";
            return;
        }
        balance -= amount;
        transactions[head] = -amount; // negative for withdrawal
        head = (head + 1) % 10;
        if (count < 10) count++;
        std::cout << "Withdrew: " << amount << ". New Balance: " << balance << "\n";
    }

    void miniStatement() const;
};

void SavingsAccount::miniStatement() const {
    std::cout << "\n--- Mini Statement for Account: " << accountNumber << " ---\n";
    std::cout << "Current Balance: " << balance << "\n";
    std::cout << "Last " << count << " transactions (Oldest to Newest):\n";

    for (int i = 0; i < count; ++i) {
        // Circular logic to print in chronological order
        // If count < 10, start at 0. If count == 10, start at head.
        int idx = (count < 10) ? i : (head + i) % 10;
        std::cout << (idx + 1) << ". " << (transactions[idx] >= 0 ? "Deposit: " : "Withdrawal: ")
                  << std::abs(transactions[idx]) << "\n";
    }
    std::cout << "--------------------------------------------\n";
}

int main() {
    SavingsAccount myAcc("SAV12345", 1000.0);

    myAcc.deposit(500.0);
    myAcc.withdraw(200.0);
    myAcc.deposit(100.0);
    myAcc.withdraw(50.0);
    myAcc.deposit(300.0);
    myAcc.withdraw(100.0);
    myAcc.deposit(1000.0);
    myAcc.withdraw(400.0);
    myAcc.deposit(200.0);
    myAcc.withdraw(100.0);

    // 10 transactions done.
    myAcc.miniStatement();

    // 11th transaction - should overwrite the 1st
    std::cout << "\nAdding 11th transaction...\n";
    myAcc.deposit(50.0);
    myAcc.miniStatement();

    return 0;
}
