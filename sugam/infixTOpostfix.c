#include <stdio.h>
#include <ctype.h>
// Infix to postfix conversion

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1; // Return -1 if stack is empty
    else
        return stack[top--];
}

// Determine the priority of an operator
int p(char x) {
    if (x == '(')
        return 0;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^')
        return 3; // Exponentiation has the highest priority
    else
        return -1; // Invalid operator
}

// Check if the operator is right-associative (only ^ is right-associative)
int isRightAssociative(char x) {
    return (x == '^');
}

int main() {
    char exp[100];
    char *e, x;
    printf("Enter the expression: ");

    // Use fgets to read a line, including spaces
    fgets(exp, sizeof(exp), stdin);  // Reads input with spaces
    printf("\nPostfix expression: ");
    
    e = exp;

    while (*e != '\0') {
        if (isalnum(*e)) { // If the character is an operand (number/letter)
            printf("%c ", *e);
        } else if (*e == '(') { // If it's an opening parenthesis
            push(*e);
        } else if (*e == ')') { // If it's a closing parenthesis
            while ((x = pop()) != '(') { // Pop until '(' is found
                printf("%c ", x);
            }
        } else { // If it's an operator
            // For left-associative operators (like +, -, *, /), pop operators with higher or equal precedence
            while (top != -1 && (p(stack[top]) > p(*e) || 
                                 (p(stack[top]) == p(*e) && !isRightAssociative(*e)))) {
                printf("%c ", pop()); // Pop higher/equal priority operators
            }
            push(*e); // Push the current operator
        }
        e++;
    }

    // Pop remaining operators from the stack
    while (top != -1) {
        printf("%c ", pop());
    }
    printf("\n");
    return 0;
}
