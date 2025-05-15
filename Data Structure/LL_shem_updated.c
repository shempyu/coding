#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *temp, *newnode;
//   typedef struct node *ll;
void create()
{

    int n;
    printf("enter number of nodes: ");
    scanf("%d", &n);
     
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        printf("enter data %d: ", i + 1);
        scanf("%d", &newnode->data);
        
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}
int len()
{
    temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void insbeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data : ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}
void insmid()
{
    if (len() >= 2)
    {
        printf("enetr the position ");
        int pos;
        scanf("%d", &pos);
        if (pos < len() && pos > 1)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("enter data: ");
            scanf("%d", &newnode->data);

            temp = head;
            int count = 1;
            while (count < pos - 1)
            {
                temp = temp->next;
                count++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else
        {
            printf("invalid position\n");
        }
    }
    else
    {
        printf("You cant \n");
    }
}
void inend()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    printf("enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}
void delbeg()
{
    if (head == NULL)
    {
        printf("ll empty: ");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void delmid()
{
    if (len() >= 3)
    {
        int x;
        printf("ener the pos: ");
        scanf("%d", &x);
        if (x < len() && x > 1)
        {
            temp = head;
            int count = 1;
            while (count < x - 1)
            {
                temp = temp->next;
                count++;
            }
            struct node *ptr;
            ptr = temp->next;
            temp->next = ptr->next;
            free(ptr);
        }
        else
        {
            printf("!!!!invalid position!!!\n");
        }
    }
    else
    {
        printf("you cant \n");
    }
}
void delend()
{
    temp = head;
    if (head == NULL)
    {
        printf("ll is empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head == NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}
void traverse()
{
    printf("data ll are: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void reverse()
{
    struct node *prev, *cure, *nxt;
    prev = NULL;
    cure = head;
    while (cure != NULL)
    {
        nxt = cure->next;
        cure->next = prev;
        prev = cure;
        cure = nxt;
    }
    head = prev;
}
void recrev(struct node *crnt, struct node *prv)
{
    if (crnt == NULL)
    {
        head = prv;
        return;
    }

    else
    {
        struct node *nxt = crnt->next;
        crnt->next = prv;
        recrev(nxt, crnt);
    }
}
int main()
{
    int ch;
    while (ch != 0)
    {
        printf("1.create \n2.insbeg\n 3.ins end\n 4.insmid \n5delbeg \n6.del end \n7.delmid \n 8 traverse\n 9 reverse \n 10.recurrev\n11 exit\n");
        printf("enetr your chpice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            insbeg();
            break;
        case 3:
            inend();
            break;
        case 4:
            insmid();
            break;
        case 5:
            delbeg();
            break;
        case 6:
            delend();
            break;
        case 7:
            delmid();
            break;
        case 8:
            traverse();
            break;
        case 9:
            reverse();
            break;
        case 10:
            recrev(head, NULL);
            break;
        case 11:
            return 0;
            break;
        default:
            printf("enetr valid choice \n");
        }
    }
    create();
    inend();
    traverse();
    return 0;
}