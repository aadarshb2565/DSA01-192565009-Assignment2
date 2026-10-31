#include <iostream>
#include <string>
#include <iomanip>

void applyByValue(double fee, double percent) {
    fee -= fee * (percent / 100.0);
    std::cout << "Inside applyByValue (local copy): " << fee << "\n";
}

void applyByReference(double& fee, double percent) {
    fee -= fee * (percent / 100.0);
}

void applyByPointer(double* fee, double percent) {
    if (fee) {
        *fee -= (*fee) * (percent / 100.0);
    }
}

int main() {
    double fee1 = 45000.0, fee2 = 45000.0, fee3 = 45000.0;
    double percent = 10.0;

    std::cout << "Initial Fee: " << fee1 << "\n\n";

    applyByValue(fee1, percent);
    std::cout << "After applyByValue: " << fee1 << " (No change)\n\n";

    applyByReference(fee2, percent);
    std::cout << "After applyByReference: " << fee2 << " (Changed)\n\n";

    applyByPointer(&fee3, percent);
    std::cout << "After applyByPointer: " << fee3 << " (Changed)\n\n";

    return 0;
}
