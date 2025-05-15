#include <stdio.h>
#define size 4
struct node
{
    int data;          // 4byte
    struct node *next; // 4byte
};
struct node *front = NULL,*rear = NULL,*newnode,*temp;

void enqueue()
{
 
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
        printf("enter the data: ");
        scanf("%d", &newnode->data);
        
    }
    else
    {
        rear->next  = newnode;
        printf("enter the dta: ");
        scanf("%d", &newnode->data);
        rear = newnode;
       
    }
}
void dequeue()
{
    if (front == NULL && rear == NULL)
        printf("queue is empty\n");
    else if (front == rear) //only one element in queue
    {
        printf("deueue element is: %d\n", front->data);
        free(front);
        front = rear = NULL;
    }
    else
    {
        temp = front;
        printf("deueue element is: %d\n", front->data);
        front = front ->next;
        free(temp);
    }
}
void peekf()
{
    printf("peek element is: %d\n", front->data);
}
void peekr()
{
    printf("peek element is: %d\n", rear->data);
}
void display()
{
    if (front == -1 && rear == -1)
        printf("queue is empty\n");
    else
    {
        printf("elements of queue are: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", qu[i]);
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
            peekf();
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