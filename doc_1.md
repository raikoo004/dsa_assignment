# Balanced Parentheses Checker Using Stack in C

## a. How the data structures are defined
This program checks whether a given mathematical expression has balanced parentheses 
(`()`, `{}`, and `[]`) using a **stack** data structure.  
The stack helps keep track of opening brackets and ensures that they are properly closed.

### Explanation
- `stack[MAX]`: A character array used to store opening brackets temporarily.
- `top`: An integer variable that keeps track of the top position of the stack.
  - `top = -1` → stack is empty
  - `top = MAX - 1` → stack is full
- The stack follows the **Last In First Out (LIFO)** principle.

---

## b. Functions implemented

### 1. `push(char value)`
- This function adds an opening bracket to the stack.
- It first checks whether the stack is full.
- If there is space, the value is stored and `top` is increased.
- It is called whenever an opening bracket is found in the expression.

---

### 2. `pop()`
- This function removes and returns the top element of the stack.
- It checks whether the stack is empty.
- If the stack is not empty, the top element (matching opening bracket) is removed.
- It is called whenever a closing bracket appears.
- Closing brackets themselves are not stored; they are only used for comparison.

---

### 3. `isBalanced(char expr[])`
- This function contains the main logic of the program.
- The expression is scanned character by character using a loop.
- Opening brackets are pushed onto the stack using `push()`.
- When a closing bracket is found:
  - The top element is popped from the stack
  - The brackets are checked for correct matching
- If a mismatch occurs or the stack becomes empty too early, the function returns `0`.
- After the scan:
  - If the stack is empty, the expression is balanced and the function returns `1`
  - Otherwise, it returns `0`

---

## c. Overview of `main()`
The `main()` function controls the execution of the program.

- Declares a character array `expr` to store the user input.
- Prompts the user to enter a mathematical expression.
- Uses `fgets()` to read the expression (supports spaces).
- Calls `isBalanced(expr)` to check bracket balance:
  - Returns `1` → prints **Balanced**
  - Returns `0` → prints **Not Balanced**
- Ends the program using `return 0`.



