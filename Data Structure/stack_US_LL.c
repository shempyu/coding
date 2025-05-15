#include <stdio.h>
#include <stdlib.h>
//stack using linked list
struct node
{
    int data;          // 4byte
    struct node *next; // 4byte
};
typedef struct node *ll;
ll top = NULL, newnode, temp;


void push()
{
    newnode = (ll)malloc(sizeof(struct node));

    printf("enter the data : \n");
    scanf("%d", &newnode->data);
        newnode->next = top;
        top = newnode;

}
void pop()
{
    if (top == NULL)
    {
        printf("stack is underflow\n");
    }
    else
    {
        temp = top;
        printf("poped : %d\n", top->data);
        top = top->next;
        free(temp);
    }
}
void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("Peek element: %d\n", top->data);
    }
}
void display()
{
    if (top == NULL)
    {
        printf("stack is underflow\n");
        return;
    }
    printf("data of linked list: ");
    temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void freeList()
{
  if (top == NULL)
    return;
  while (top != NULL)
  {
    temp = top;
    top = top->next;
    free(temp); // Free each node to prevent memory leaks
  }
  printf("linked list deallocated\n");
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
            freeList();
            return 5;
            break;
        default:
            printf("invalid operation\n");
        }
    }
    freeList();
    return 0;
}