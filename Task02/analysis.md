# Task 02 - Return by Reference and Its Dangers

## Implementation

### 1. High Mark Moderation
`Task02/marks_register.cpp` implements:
- `int& findHighest(int arr[], int size)`: Returns a reference to the highest element.
- Moderation logic: `findHighest(marks, n) += 2;` (using the call on the left of `=`).

### 2. The Dangling Reference Danger
`Task02/dangling_ref.cpp` demonstrates returning a reference to a local variable. 
- **Compiler Warning:** Modern compilers (like g++) issue a warning: `warning: reference to local variable 'max' returned`.
- **Undefined Behaviour:** The local variable is destroyed when the function exits. Returning a reference to it means the caller gets a "dangling reference" to a memory location that may be overwritten by other functions, leading to unpredictable values or segmentation faults.

### 3. Reference vs Const Reference vs Copy
- **Return by Reference (`int&`):** Returns an alias. Allows modification of the original. Fast (no copy).
- **Return by Const Reference (`const int&`):** Returns an alias but prevents modification. Fast.
- **Return by Copy (`int`):** Returns a new value. Original cannot be modified. Slightly slower for large objects, but safest.

---

## Changed Condition: std::vector Growth
When using a `std::vector`, if a reference to an element is obtained (e.g., `int& ref = vec[0];`) and the vector subsequently grows (via `push_back`), the vector may reallocate its internal storage to a new, larger memory block. The old memory is freed, making the previously obtained reference **invalid** (dangling).

---

## Alternative Concept and Complexity Analysis

### Index vs Pointer vs Reference
- **Index (`int`):** `int idx = findHighestIndex(marks, n); marks[idx] += 2;`
- **Pointer (`int*`):** `int* ptr = findHighestPtr(marks, n); *ptr += 2;`
- **Reference (`int&`):** `findHighest(marks, n) += 2;`

**Complexity Analysis:**
- **Time Complexity:** All three are $O(n)$ as they must scan the array once.
- **Space Complexity:** All three are $O(1)$.

**Safety Comparison (with Growing Vector):**
- **Reference/Pointer:** Extremely unsafe. Both become invalid immediately upon reallocation.
- **Index:** Safest. The index remains valid as long as the element is not deleted, regardless of where the vector moves in memory.

---

## Evidence Expected
- `marks_register.cpp`: Working moderation via reference.
- `dangling_ref.cpp`: Code causing compiler warnings and exhibiting UB.
- Analysis of vector reallocation risks.
