#include <stdio.h>
#include <string.h>

int a[100];
int top = -1;
void push(int data)
{
  a[++top] = data;
}

int pop()
{
    if (top == -1)
        return -1;
    else
        return a[top--];
}

int evalpost(char *exp)
{
    int len = strlen(exp);
    for (int i = 0; i < len; i++)
    {
        if (exp[i] != '*' && exp[i] != '+' && exp[i] != '-' && exp[i] != '/')
        {
            if (exp[i] >= '0' && exp[i] <= '9')
            {
                push(exp[i] - '0'); // Convert char digit to integer
            }
            else
            {
                printf("Invalid character: %c\n", exp[i]);
                return -1; // Error for invalid character
            }
        }
        else
        {
            int op1 = pop();
            int op2 = pop();

            if (op1 == -1 || op2 == -1)
            {
                return -1; // Handle underflow error
            }

            int result;
            switch (exp[i])
            {
            case '+':result = op2 + op1;break;
            case '-': result = op2 - op1; break;
            case '*': result = op2 * op1; break;
            case '/':
                if (op1 == 0)
                {
                    printf("Division by zero error\n");
                    return -1;
                }
                result = op2 / op1;
                break;
            default:
                printf("Unexpected operator: %c\n", exp[i]);
                return -1; // Safety fallback
            }
            push(result);
        }
    }

    if (top == 0)
    { // Only one item should remain in the stack
        return pop();
    }
    else
    {
        printf("Invalid postfix expression\n");
        return -1; // More or fewer elements indicate an error
    }
}

int main()
{
    char exp[100];
    printf("Enter the expression: ");
    scanf("%s", exp);
    int result = evalpost(exp);

    if (result != -1)
    {
        printf("Evaluated expression: %d\n", result);
    }

    return 0;
}
