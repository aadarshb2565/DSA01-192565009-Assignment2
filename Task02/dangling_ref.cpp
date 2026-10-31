#include <iostream>

// DANGEROUS FUNCTION: Returns a reference to a local variable
int& getDanglingReference() {
    int localVal = 100;
    return localVal; // Compiler warning: reference to local variable returned
}

int main() {
    std::cout << "Attempting to access a dangling reference...\n";
    int& ref = getDanglingReference();

    // This is Undefined Behaviour (UB).
    // The value might be 100, or it might be garbage.
    std::cout << "Value: " << ref << "\n";

    return 0;
}
