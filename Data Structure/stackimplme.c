#include <stdio.h>
#define size 5
int a[size];
int top = -1;

int isFull()
{
    if (top == size -1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push()
{
    if (isFull())
    {
        printf("stack is overflow\n");
    }
    else
    {
        int x;
        printf("enter the data: ");
        scanf("%d", &x);
        top = top + 1;
        a[top] = x;
    }
}
void pop()
{
    if (isEmpty())
    {
        printf("stack is underflow\n");
    }
    else
    {
        printf("poped : %d\n", a[top]);
        top = top - 1;
    }
}
void peek()
{
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Peek element: %d\n", a[top]);
    }
}
void display()
{
    if (isEmpty())
        printf("stack is underflow\n");
    else
    {
        printf("elements of stack: \n");
        for (int i = top; i >= 0; i--)
            printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int ch = 0;
    while (ch != 5)
    {
        printf("Stack operation\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter the operation to be performed: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            return 5 ;
        default:
            printf("invalid operation\n");
        }
    }
    return 0;
}