#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Stack structure
struct Stack {
    int top;
    int items[MAX];
};

// Stack operations
void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    s->items[++s->top] = value;
}

int pop(struct Stack *s) {
    return s->items[s->top--];
}

// Operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Infix to Postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack s;
    initStack(&s);
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(&s, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(&s) && s.items[s.top] != '(')
                postfix[k++] = pop(&s);
            pop(&s); // remove '('
        }
        else {
            while (!isEmpty(&s) && precedence(s.items[s.top]) >= precedence(ch))
                postfix[k++] = pop(&s);
            push(&s, ch);
        }
    }

    while (!isEmpty(&s))
        postfix[k++] = pop(&s);

    postfix[k] = '\0';
}

// Evaluate Postfix expression
int evaluatePostfix(char postfix[]) {
    struct Stack s;
    initStack(&s);
    int i;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else {
            int b = pop(&s);
            int a = pop(&s);

            switch (ch) {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
                case '^': push(&s, pow(a, b)); break;
            }
        }
    }
    return pop(&s);
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    printf("Evaluation result: %d\n", evaluatePostfix(postfix));

    return 0;
}
