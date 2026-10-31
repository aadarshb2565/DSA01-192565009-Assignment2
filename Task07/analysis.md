# Task 07 - Diagnose, Redesign and Validate

## A. Diagnose the Limitation
**Selected Program:** `Task04/savings_account.cpp` (Mini-Statement)

**Limitation:** The current design uses a fixed-size array `double transactions[10]`.
- **Evidence:** If the bank requirement changes to the last 50 or 100 transactions, we must manually change the array size and recompile.
- **Core Issue:** Fixed-size arrays are allocated on the stack and their size must be known at compile-time. They lack the flexibility to grow based on user needs or configuration.

## B. Define the Design Objective
**Objective:** Implement a transaction history system that supports a **configurable** number of recent transactions (set at runtime) while maintaining $O(1)$ insertion time.

## C. Design the Revised Solution
**Redesign:** Replace the fixed array with a `std::vector<double>` used as a circular buffer.

**Changes:**
1. **Dynamic Size:** The constructor now takes `int maxHistory`.
2. **Vector Buffer:** `std::vector<double> transactions` initialized to `maxHistory`.
3. **Circular Logic:** Retain the `head` index and modulo operator: `head = (head + 1) % transactions.size()`.

**Trade-off:**
- **Memory:** Small overhead for `std::vector` metadata and heap allocation.
- **Complexity:** Transition from stack allocation to heap allocation.

## D. Predict Before Implementing
**Prediction:** The redesigned system will handle any history size (e.g., 10, 50, 1000) without requiring code changes or recompilation, while keeping the `deposit()` and `withdraw()` operations at $O(1)$.

## E. Implement and Validate
`Task07/redesigned_savings.cpp` implements this change.

**Comparison:**
| Feature | Original (Fixed Array) | Redesigned (Vector Circular) |
|---|---|---|
| Size Change | Requires Recompile | Runtime Configurable |
| Insertion Time | $O(1)$ | $O(1)$ |
| Memory Location | Stack | Heap |
| Scalability | Poor | Excellent |

## F. Defend the Final Design
The objective was achieved. The system is now future-proof; if the bank decides to store 100 transactions, we simply pass `100` to the constructor. The original design was preferable only in extremely memory-constrained embedded systems where heap allocation is forbidden. For a banking application, the flexibility of `std::vector` far outweighs the negligible memory cost.
