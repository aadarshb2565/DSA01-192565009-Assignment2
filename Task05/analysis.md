# Task 05 - Static Members and Arrays of Objects

## Implementation

### 1. BusTicket Class Design
`Task05/bus_tickets.cpp` implements the ticket system:
- **Static Data Member:** `static int issued;` (Shared across all objects to track total seats).
- **Static Member Function:** `static int count();` (Returns the total issued tickets without needing a specific object).
- **Logic:** The constructor increments `issued` and assigns a seat number only if `issued <= CAPACITY`. Otherwise, the ticket is marked as "Waiting".

### 2. Array of Objects
The program creates an array `BusTicket trip[4]` (where capacity is 3), demonstrating that the 4th object correctly enters the waiting list.

---

## Inquiry & Design

**Static Member Placement:**
- **Declaration:** Inside the class.
- **Definition:** Outside the class (e.g., `int BusTicket::issued = 0;`). This is mandatory because the static member exists independently of any object; the definition allocates the actual memory for it.

**Static Member Functions:**
A static member function cannot access non-static members because it doesn't have a `this` pointer. It doesn't belong to any specific instance, so it doesn't know which object's data to access. It can only access other static members.

**Behavior in Loops/Functions:**
Since `issued` is static, its value persists across all function calls and loop iterations. Even if `BusTicket` objects are created inside a local function that returns, the `issued` count remains incremented for the next set of objects created elsewhere.

---

## Predict the Output

**Program Snippet:**
```cpp
class Token {
    static int next;
    int id;
public:
    Token() { id = ++next; }
    int get() const { return id; }
    static int issued() { return next - 100; }
};
int Token::next = 100;
// ... main ...
Token counter[3];
Token extra;
std::cout << counter[0].get() << ' ' << counter[2].get() << ' ' << extra.get() << ' ' << Token::issued() << '\n';
```

**My predicted output:**
```
101 103 104 4
```

**Explanation:**
- `Token counter[3]` runs the constructor 3 times: `next` becomes 101, 102, 103.
- `Token extra` runs the constructor 1 time: `next` becomes 104.
- `counter[0].get()` is 101.
- `counter[2].get()` is 103.
- `extra.get()` is 104.
- `Token::issued()` is `104 - 100 = 4`.
- Total constructor calls: 4.

---

## Alternative Concept and Complexity Analysis

**Alternative: Global Variable vs TicketOffice Object**
- **Global Variable:** `int totalIssued;` 
  - Pros: Simple. 
  - Cons: No encapsulation; any function can reset the count.
- **TicketOffice Object:** `TicketOffice office;` passed to every `BusTicket`.
  - Pros: Encapsulated. Allows multiple buses (each bus has its own `TicketOffice`).
  - Cons: Higher boilerplate (passing pointers/references).

**Complexity Analysis:**
- **Time Complexity:** All $O(1)$ for incrementing and retrieving.
- **Space Complexity:** All $O(1)$ (one integer).

**Verdict:** Static members are best for single-instance shared state. For multiple buses, a `TicketOffice` object (or making `BusTicket` a member of a `Bus` class) is necessary.
