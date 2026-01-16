# Infix to Postfix Conversion and Evaluation

## (a) Data Structures Used

The program uses a **stack** implemented using an array.  
The stack structure contains:
- `top`: An integer to track the top of the stack
- `items[]`: An array to store stack elements

The stack is used:
- During infix to postfix conversion to store operators
- During postfix evaluation to store operands

---

## (b) Functions Implemented

### `initStack(struct Stack *s)`
Initializes the stack by setting `top` to -1.

### `isEmpty(struct Stack *s)`
Checks whether the stack is empty.

### `push(struct Stack *s, int value)`
Pushes an element onto the stack.

### `pop(struct Stack *s)`
Removes and returns the top element from the stack.

### `precedence(char op)`
Returns the precedence value of operators (`+`, `-`, `*`, `/`, `^`).

### `infixToPostfix(char infix[], char postfix[])`
Converts an infix expression into postfix notation using a stack.

### `evaluatePostfix(char postfix[])`
Evaluates a postfix expression using a stack and returns the result.

---

## (c) Organization of the `main()` Function

The `main()` function performs the following steps:
1. Reads the infix expression from the user
2. Converts the infix expression to postfix
3. Displays the postfix expression
4. Evaluates the postfix expression
5. Displays the final result


