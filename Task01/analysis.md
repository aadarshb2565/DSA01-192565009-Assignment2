# Task 01 - Call by Value, Reference, and Pointer

## Predict the Output
**Program:**
```cpp
#include <iostream>

void change(int a, int& b, int* c)
{
    a += 10;
    b += 10;
    *c += 10;
}

int& bigger(int& p, int& q) { return p > q ? p : q; }

void show(int x, int y = 5, int z = 10) { std::cout << x + y + z << ' '; }

int main()
{
    int a = 1, b = 2, c = 3;
    change(a, b, &c);
    std::cout << a << ' ' << b << ' ' << c << '\n';

    bigger(a, c) = 100;
    std::cout << a << ' ' << c << '\n';

    show(1);
    show(1, 2);
    show(1, 2, 3);
    std::cout << '\n';
}
```

**My predicted output:**
```
1 12 13
1 100
16 17 18
```

**Explanation:**
- `change(a, b, &c)`: `a` is passed by value (local copy, no change to original), `b` is passed by reference (original changes), `c` is passed by pointer (original changes).
- `bigger(a, c) = 100`: `bigger` returns a reference to the larger of `a` (1) and `c` (13), which is `c`. Assigning 100 to the result changes `c` to 100.
- `show(1)`: uses defaults `y=5, z=10`. Sum = 1+5+10 = 16.
- `show(1, 2)`: uses default `z=10`. Sum = 1+2+10 = 13. Wait, let me re-calculate. `show(1, 2)` is 1+2+10 = 13.
- `show(1, 2, 3)`: Sum = 1+2+3 = 6.

**Revised Prediction:**
```
1 12 13
1 100
16 13 6
```

---

## Implementations

### 1. Concession Function (Three Ways)
`Task01/concession.cpp` implements the three ways:
- By Value: `void apply(double fee, ...)`
- By Reference: `void apply(double& fee, ...)`
- By Pointer: `void apply(double* fee, ...)`

### 2. Complete the Code
`Task01/complete_code.cpp` implements the required TODO.

---

## Inquiry & Design

**Parameter Storage:**
- **Call by Value:** Parameter is stored in a new memory location on the stack (local copy). Changes are local.
- **Call by Reference:** Parameter is an alias for the original variable. No new memory for the value is allocated; it points to the original.
- **Call by Pointer:** Parameter is a local variable that stores the address of the original variable.

**Const Reference:** Use `const T&` when passing large objects (like a `Student` class) to avoid expensive copies while ensuring the function cannot modify the original object.

**Design Decision:**
For multiple concessions, I recommend **returning the new fee** or using **call by reference**. However, returning the value is often cleaner for chaining (e.g., `fee = apply(apply(fee, 10), 5)`), whereas in-place modification is more memory efficient for very large objects. For a simple `long long` fee, returning the value is preferred for functional purity.

---

## Alternative Concept and Complexity Analysis

**Returning Value vs Reference:**
If `long long applyConcession(long long fee, int percent)` is used, the caller must assign the result back: `hostelFee = applyConcession(hostelFee, 10);`.

**Space Complexity Analysis:**
- **long long (8 bytes):**
  - By Value: 8 bytes copied.
  - By Reference: 8 bytes (pointer size) copied.
  - Negligible difference.
- **Large Student Object (e.g., 1 KB):**
  - By Value: 1024 bytes copied every call.
  - By Reference/Const Reference: 8 bytes copied.
  - Significant performance gain with references.

**Time Complexity:** All versions are $O(1)$.
