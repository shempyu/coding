#include <stdio.h>
#include <string.h>
#define size 10

int a[size];
int top = -1;

int isFull() {
    return top == size - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int data) {
    if (isFull()) {
        printf("Stack Overflow\n");
    } else {
        a[++top] = data;
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return a[top--];
    }
}

int evalprefix(char *exp) {
    int len = strlen(exp);

    // Traverse the expression from right to left
    for (int i = len - 1; i >= 0; i--) {
        if (exp[i] != '*' && exp[i] != '+' && exp[i] != '-' && exp[i] != '/') {
            if (exp[i] >= '0' && exp[i] <= '9') {
                push(exp[i] - '0'); // Convert char digit to integer
            } else {
                printf("Invalid character: %c\n", exp[i]);
                return -1; // Error for invalid character
            }
        } else {
            int op1 = pop();
            int op2 = pop();

            if (op1 == -1 || op2 == -1) {
                return -1; // Handle underflow error
            }

            int result;
            switch (exp[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': 
                    if (op2 == 0) {
                        printf("Division by zero error\n");
                        return -1;
                    }
                    result = op1 / op2;
                    break;
                default:
                    printf("Unexpected operator: %c\n", exp[i]);
                    return -1; // Safety fallback
            }
            push(result);
        }
    }

    if (top == 0) { // Only one item should remain in the stack
        return pop();
    } else {
        printf("Invalid prefix expression\n");
        return -1; // More or fewer elements indicate an error
    }
}

int main() {
    char exp[100];
    printf("Enter the prefix expression: ");
    scanf("%s", exp);
    int result = evalprefix(exp);

    if (result != -1) {
        printf("Evaluated result: %d\n", result);
    }

    return 0;
}
