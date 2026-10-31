DSA0102 Assignment 2 - Advanced C++ Concepts

Student: Aadarsh. B
Register Number: 192565009
Compiler: g++ 13
Standard: C++17

Compilation Command
g++ -std=c++17 -Wall -Wextra -o <output> <source.cpp>

Repository Structure
Task01/  - Call by Value, Reference and Pointer (analysis.md, concession.cpp, complete_code.cpp, predict_output.cpp)
Task02/  - Return by Reference and Its Dangers (analysis.md, marks_register.cpp, dangling_ref.cpp)
Task03/  - Default Arguments and Function Overloading (analysis.md, courier_charge.cpp)
Task04/  - Specifying a Class with an Array Inside It (analysis.md, savings_account.cpp)
Task05/  - Static Members and Arrays of Objects (analysis.md, bus_tickets.cpp, predict_output.cpp)
Task06/  - Friend Functions and Inline Functions (analysis.md, train_planner.cpp)
Task07/  - Diagnose, Redesign and Validate (analysis.md, redesigned_savings.cpp)

How to Run

Task 1 - Concessions
cd Task01
g++ -std=c++17 -Wall -Wextra -o concession concession.cpp
./concession

Task 2 - Marks Register
cd Task02
g++ -std=c++17 -Wall -Wextra -o marks_register marks_register.cpp
./marks_register

Task 3 - Courier Charge
cd Task03
g++ -std=c++17 -Wall -Wextra -o courier_charge courier_charge.cpp
./courier_charge

Task 4 - Savings Account
cd Task04
g++ -std=c++17 -Wall -Wextra -o savings_account savings_account.cpp
./savings_account

Task 5 - Bus Tickets
cd Task05
g++ -std=c++17 -Wall -Wextra -o bus_tickets bus_tickets.cpp
./bus_tickets

Task 6 - Train Planner
cd Task06
g++ -std=c++17 -Wall -Wextra -o train_planner train_planner.cpp
./train_planner

Task 7 - Redesigned Savings
cd Task07
g++ -std=c++17 -Wall -Wextra -o redesigned_savings redesigned_savings.cpp
./redesigned_savings

Key Results Summary

Task 1: Verified stored fee changes for reference/pointer but not for value passing
Task 2: Demonstrated that returning a reference to a local variable causes undefined behavior
Task 3: Resolved ambiguity by overloading functions for int, double, and Parcel types
Task 4: Implemented circular index in SavingsAccount to store last 10 transactions in O(1)
Task 5: Used static data members to track total issued tickets across all BusTicket objects
Task 6: Used friend functions for symmetric Time comparison and analyzed inline optimization
Task 7: Redesigned transaction history using std::vector circular buffer for runtime flexibility

Design Decisions

1. Circular Buffer for Transactions — Ensures O(1) insertion and fixed memory footprint
2. Static Seat Counter — Maintains class-level state independent of individual ticket objects
3. Friend Functions for Time — Allows access to private members while maintaining a clean, non-member API
4. Function Overloading for Charges — Handles different unit types (grams, kg) without ambiguity
5. Pass-by-Reference for Large Objects — Prevents expensive copying of objects while allowing mutation
6. Dynamic Vector for History — Permits bank to change history size without recompiling code
