#include <stdio.h>
#include <stdlib.h>
//queu using linked list
struct node
{
    int data;          // 4byte
    struct node *next; // 4byte
};
typedef struct node *ll;
ll front = NULL, rear = NULL, newnode, temp;

void enqueue()
{
    newnode = (ll)malloc(sizeof(struct node));
    newnode->next = NULL;

    
    if (front == NULL && rear == NULL)
    {
        printf("enter the data : ");
        scanf("%d", &newnode->data);
        front = rear = newnode;
        
    }
    else
    {
        printf("enter the data : ");
        scanf("%d", &newnode->data);
        rear->next = newnode;
        rear = newnode;   
    }
}
void dequeue()
{
    if (front == NULL && rear == NULL)
        printf("queue is empty\n");
    else if (front == rear) // only one element in queue
    {
        printf("deueue element is: %d\n", front->data);
        free(front);
        front = rear = NULL;
    }
    else
    {
        temp = front;
        printf("deueue element is: %d\n", front->data);
        front = front->next;
        free(temp);
    }
}
void peekfront()
{
    if (front == NULL)
    {
        printf("qu is empty\n");
        return;
    }
    printf("peek element is: %d\n", front->data);
}
void peekr()
{
    if (rear == NULL)
    {
        printf("qu is empty\n");
        return;
    }
    printf("peek element is: %d\n", rear->data);
}
void display()
{
    if (front == NULL && rear == NULL)
        printf("queue is empty\n");
    else
    {
        printf("elements of queue are: ");
        temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    int ch;
    while (1)
    {
        printf("Queue operation\n");
        printf("1. Enqueue operation\n");
        printf("2. Dequeue operation\n");
        printf("3. Peek front operation\n");
        printf("4. Peek rear operation\n");
        printf("5. Display operation\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peekfront();
            break;
        case 4:
            peekr();
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        default:
            printf("enter valid input\n");
        }
    }
}