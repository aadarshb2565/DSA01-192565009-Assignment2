# Task 06 - Friend Functions and Inline Functions

## Implementation

### 1. Time Class Design
`Task06/train_planner.cpp` implements:
- **Private Data:** `int h, m;`
- **Friend Functions:** `minutesBetween()` and `earlier()`.
- **Inline Suggestion:** Small functions like `earlier` are candidates for `inline` to reduce function call overhead.

---

## Inquiry & Design

**Why a Friend Function?**
The `minutesBetween` and `earlier` functions operate on **two** `Time` objects equally. If implemented as a member function, one object would be the "owner" (`this`) and the other would be a parameter. A friend function provides a symmetric interface: `earlier(t1, t2)`.

**Friend vs Member Functions:**
- **Access:** Both can access private members.
- **Calling Convention:** Member functions are called via `t1.earlier(t2)`. Friend functions are called as standalone functions `earlier(t1, t2)`.
- **Context:** Member functions have a `this` pointer; friend functions do not.

**Inline Functions:**
The `inline` keyword is a **hint** to the compiler to replace the function call with the actual function body. This eliminates the overhead of pushing arguments to the stack and jumping to a different address. 
- **When to use:** Small, frequently called functions (like time comparisons).

**Public Members Risk:**
If `h` and `m` were public, any part of the program could set `m = 99` or `h = 25`, breaking the internal consistency of the `Time` class. Encapsulation ensures that only valid times are stored.

---

## Growth Investigation (Inline Performance)

**Observation:**
- **-O0 (No Optimization):** `inline` may provide a slight speedup by reducing call overhead.
- **-O2 (Optimized):** The compiler's optimizer often inlines functions automatically, regardless of the `inline` keyword. The performance difference between `inline` and non-`inline` usually disappears at high optimization levels.

---

## Alternative Concept and Complexity Analysis

**Alternative: Member Functions vs Getters**
- **Member Function (`t1.earlier(t2)`):** Similar to friend functions. Encapsulated.
- **Public Getters (`t1.getHours()`):** Allows any function to compare times, but exposes internal state.

**Comparison:**
- **Time Complexity:** All $O(1)$.
- **Encapsulation:** Friend functions > Member functions > Getters. Friend functions keep data private while allowing specific, trusted external functions to access it.

**Verdict:** Friend functions are the best design here as they maintain strict encapsulation while providing a symmetric, clean API for comparisons.
