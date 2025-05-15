#include <stdio.h>
#define size 4
//circular queue
int qu[size], x;
int front = -1;
int rear = -1;

void enqueue()
{
    if ((rear+1)%size==front){
        printf("queue is full\n");     
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        printf("enter the data: ");
        scanf("%d", &x);
        qu[rear] = x;
    }
    else
    {
        rear = (rear + 1)%size;
        printf("enter the dta: ");
        scanf("%d", &x);
        qu[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
        printf("queue is empty\n");
    else if (front == rear) //only one element in queue
    {
        printf("deueue element is: %d\n", qu[front]);
        front = rear = -1;
    }
    else
    {
        printf("deueue element is: %d\n", qu[front]);
        front = (front + 1)%size;
    }
}
void peekf()
{
    printf("peek element is: %d\n", qu[front]);
}
void peekr()
{
    printf("peek element is: %d\n", qu[rear]);
}
void display()
{
    if (front == -1 && rear == -1)
        printf("queue is empty\n");
    else
    {
        printf("elements of queue are: ");
        for (int i = front; ; i = (i+1)%size)
        {
            printf("%d ", qu[i]);
            if(i==rear)
            break;
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