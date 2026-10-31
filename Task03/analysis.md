# Task 03 - Default Arguments and Function Overloading

## The Ambiguity Problem

**Scenario:**
The developer implemented:
1. `charge(double weight)`
2. `charge(double weight, bool express)`
3. `charge(double weight, bool express = false, bool insured = false)`

**Why it fails to compile:**
The call `charge(10.5)` is **ambiguous**. The compiler cannot decide whether to call function (1) with one argument or function (3) using its default arguments for `express` and `insured`. Similarly, `charge(10.5, true)` matches both (2) and (3).

---

## Redesigned Solution

To resolve ambiguity and handle different input types, I have used **Function Overloading** based on types and a single function with **Default Arguments** for the options.

### Overloaded Signatures:
1. `double charge(int weightGrams)` $\rightarrow$ Handles weight in grams.
2. `double charge(double weightKg)` $\rightarrow$ Handles weight in kilograms.
3. `double charge(const Parcel& p)` $\rightarrow$ Handles a Parcel object.
4. `double charge(double weightKg, bool express, bool insured)` $\rightarrow$ The base calculation logic.

To keep common calls short, I provide a wrapper or use the most general overload with defaults:
`double charge(double weightKg, bool express = false, bool insured = false)`

### Predicted Selections:
| Call | Selected Function | Reason |
|---|---|---|
| `charge(500)` | `charge(int)` | Exact match for `int`. |
| `charge(2.5)` | `charge(double, bool=false, bool=false)` | Exact match for `double`. |
| `charge(2.0f)` | `charge(double, ...)` | `float` promotes to `double`. |
| `charge(2.5, true)` | `charge(double, bool, bool=false)` | Exact match for `double, bool`. |
| `charge(myParcel)` | `charge(const Parcel&)` | Exact match for `Parcel` object. |
| `charge(2.5, true, true)` | `charge(double, bool, bool)` | Exact match for all three. |

---

## Inquiry

**Overload Resolution Process:**
1. **Exact Match:** Compiler looks for a function where types match exactly.
2. **Promotion:** If no exact match, types are promoted (e.g., `char` $\rightarrow$ `int`, `float` $\rightarrow$ `double`).
3. **Standard Conversion:** If still no match, it tries implicit conversions (e.g., `int` $\rightarrow$ `double`).
4. **Ambiguity:** If multiple functions match equally well, the compiler throws an error.

**Right-to-Left Defaults:**
Default arguments must be given from right to left because the compiler assigns arguments positionally. If a middle argument had a default but the rightmost didn't, the compiler wouldn't know if a missing argument was intended for the middle one or if the rightmost one was simply omitted.

---

## Alternative Concept and Complexity Analysis

**Alternative: Single Parcel Structure**
Instead of overloading, we could use a `ChargeRequest` struct:
```cpp
struct ChargeRequest {
    double weight;
    bool express = false;
    bool insured = false;
    // ... other options
};
double calculateCharge(const ChargeRequest& req);
```

**Comparison:**
- **Overload Resolution Time:** Happens at **compile time**. There is zero runtime cost for deciding which function to call.
- **Space Complexity:** 
  - Overloading: Small stack frames for each call.
  - Struct: Passes one reference (8 bytes) to the function.
- **Extensibility:** Adding a new option (e.g., `fragile`) requires changing the function signature in overloading (breaking existing calls if not defaulted), whereas adding a field to the `ChargeRequest` struct preserves the function signature.
