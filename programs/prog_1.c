// Program to check balanced parentheses using stack
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;
// Push function
void push(char value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack[++top] = value;
    }
}
// Pop function
char pop()
{
    if (top == -1)
    {
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}
// Function to check balanced parentheses
int isBalanced(char expr[])
{
    top = -1;  // reset stack

    for (int i = 0; i < strlen(expr); i++)
    {
        char ch = expr[i];

        // Opening brackets
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }

        // Closing brackets
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
            {
                return 0;  // no matching opening bracket
            }

            char open = pop();

            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '['))
            {
                return 0;
            }
        }
    }

    return (top == -1); // balanced if stack empty
}
int main()
{
    char expr[MAX];

    printf("Enter expression: ");
    fgets(expr, MAX, stdin);  // reads spaces

    if (isBalanced(expr))
    {
        printf("The parentheses are balanced\n");
    }
    else
    {
        printf("The parentheses are not balanced\n");
    }

    return 0;
}
