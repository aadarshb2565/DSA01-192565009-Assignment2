# Task 04 - Specifying a Class with an Array Inside It

## Implementation

### 1. SavingsAccount Class
`Task04/savings_account.cpp` implements:
- **Private Data:**
  - `std::string accountNumber`
  - `double balance`
  - `double transactions[10]` (Fixed array for mini-statement)
  - `int count` (Number of transactions)
  - `int head` (Circular index for the most recent transaction)
- **Public Member Functions:**
  - `deposit(double amount)`: Adds to balance, records transaction.
  - `withdraw(double amount)`: Subtracts from balance (if sufficient), records transaction.
  - `miniStatement()`: Prints the last 10 transactions in chronological order.

### 2. Member Function Definition
- **Inside Class:** `deposit()` and `withdraw()` are defined inside the class for brevity.
- **Outside Class:** `miniStatement()` is defined outside the class using the scope resolution operator `SavingsAccount::miniStatement()`.

---

## Inquiry & Design

**Why the array must be private:**
The transaction array and the `head` index must be private to prevent external code from arbitrarily modifying the transaction history or corrupting the circular index, which would lead to incorrect mini-statements.

**Handling the 11th Transaction:**
- **Shifting the Array:** Every time a new transaction arrives after the 10th, we shift elements 1-9 to 0-8. 
  - **Cost:** $O(k)$ where $k$ is array size.
- **Circular Index (Implemented):** We use a `head` index that wraps around using the modulo operator: `head = (head + 1) % 10`.
  - **Cost:** $O(1)$.
  - **Logic:** The newest element always overwrites the oldest.

**Design Decision (Expanding to 50 Transactions):**
Increasing the capacity to 50 is a trivial change if using a fixed array (just change the constant `10` to `50`). The circular index design is highly scalable as it maintains $O(1)$ insertion regardless of array size.

---

## Alternative Concept and Complexity Analysis

**Alternative: std::deque vs Circular Buffer**
- **std::deque:** Use `push_back()` and if `size() > 10`, `pop_front()`.
  - **Time (Add):** $O(1)$.
  - **Space:** Dynamic allocation overhead.
- **Circular Buffer (Fixed Array):** Use a fixed array and a wrap-around index.
  - **Time (Add):** $O(1)$.
  - **Space:** Minimal (exactly 10 * sizeof(double)).

**Comparison:**
For a small, fixed number of transactions (10 or 50), the **Circular Buffer with a fixed array** is superior because it avoids dynamic memory allocation and fragmentation while maintaining optimal time complexity.
