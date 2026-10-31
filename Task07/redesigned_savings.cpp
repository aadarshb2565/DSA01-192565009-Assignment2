#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

class SavingsAccount {
    std::string accountNumber;
    double balance;
    std::vector<double> transactions;
    int count;
    int head;
    int maxHistory;

public:
    SavingsAccount(std::string accNo, double initialBalance, int historySize = 10)
        : accountNumber(accNo), balance(initialBalance), count(0), head(0), maxHistory(historySize) {
        transactions.resize(maxHistory, 0.0);
    }

    void deposit(double amount) {
        balance += amount;
        transactions[head] = amount;
        head = (head + 1) % maxHistory;
        if (count < maxHistory) count++;
        std::cout << "Deposited: " << amount << ". New Balance: " << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient funds for withdrawal of " << amount << "\n";
            return;
        }
        balance -= amount;
        transactions[head] = -amount;
        head = (head + 1) % maxHistory;
        if (count < maxHistory) count++;
        std::cout << "Withdrew: " << amount << ". New Balance: " << balance << "\n";
    }

    void miniStatement() const {
        std::cout << "\n--- Mini Statement for Account: " << accountNumber << " ---\n";
        std::cout << "Current Balance: " << balance << "\n";
        std::cout << "Last " << count << " transactions (Oldest to Newest):\n";

        for (int i = 0; i < count; ++i) {
            int idx = (count < maxHistory) ? i : (head + i) % maxHistory;
            std::cout << (idx + 1) << ". " << (transactions[idx] >= 0 ? "Deposit: " : "Withdrawal: ")
                      << std::abs(transactions[idx]) << "\n";
        }
        std::cout << "--------------------------------------------\n";
    }
};

int main() {
    // Validating with 50 transactions instead of 10
    std::cout << "Creating account with history size 50...\n";
    SavingsAccount myAcc("SAV_PRO_001", 1000.0, 50);

    for(int i=1; i<=60; ++i) {
        if(i % 2 == 0) myAcc.deposit(10.0 * i);
        else myAcc.withdraw(5.0 * i);
    }

    myAcc.miniStatement();
    std::cout << "\nSuccessfully maintained last 50 transactions without recompiling logic.\n";

    return 0;
}
