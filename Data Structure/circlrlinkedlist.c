#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;          // 4byte
    struct node *next; // 4byte
};
typedef struct node *ll;
ll  newnode, tail = NULL,temp,head;
void create()
{
    int n, i;
    printf("how many node are needed :\n");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid number of nodes.\n");
        return;
    }
    for (i = 1; i <= n; i++)
    {
        newnode = (ll)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        newnode->next = NULL;
        printf("enter the data %d: \n", i);
        scanf("%d", &newnode->data);
    
        if (tail == NULL){
            tail = newnode;//tail= head=newnode;
           tail->next = newnode;
           //tail->next = head
          }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
          //  tail->next = head;
        }
     //tail->next=head;
    }
    
}
void traverse()
{
    if (tail == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    printf("data of linked list: ");
    temp = tail->next;
    while(temp->next != tail->next)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d \n", temp->data);

}
void insBeg()
{
    newnode = (ll)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
       printf("Enter data: ");
    scanf("%d", &newnode->data);
    if(tail == NULL){
         // If the list is empty, the new node points to itself
        tail = newnode;
        tail->next = newnode;
    }
    else{
      
        newnode->next = tail->next;
        tail->next = newnode;
    
    }
}

void insEnd()
{
    newnode = (ll)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    // newnode->data = 55; // Arbitrary value (can be made input-based)
    newnode->next = NULL;

    if (tail == NULL)
    {
        tail = newnode; // If list is empty, head is the same
        newnode->next = tail;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}
int getlength()
{
    temp = tail->next;
    int count = 0;
    do
    {
        count++;
        temp = temp->next; // Move to the next node
    } while(temp != tail);
    return count;
}

void insMiddle()
{
    int x, pos, count = 1;
    printf("Enter position after which you want to insert the node: ");
    scanf("%d", &pos);
    if (pos > getlength() ||pos < 0)
        printf("invalid position\n");
    else if(pos == 1){
        insBeg();
    }
    else
    {
        temp = tail->next;
        while (count < pos)
        {
            temp = temp->next; // at the required node
            count++;
        }
        newnode = (ll)malloc(sizeof(struct node));
        newnode->next = NULL;
        printf("Enter data: ");
        scanf("%d", &x);
        newnode->data = x;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void delBeg()
{
    temp = tail->next;
    if (tail == NULL)
    {
        printf("List is empty. Deletion not possible.\n");
    }
    else if(temp->next == tail)
    {
        tail = NULL;
        free(temp);
        
    }
    else{
        tail->next = temp->next;
        free(temp);
    }
}

void delEnd()
{
     temp = tail->next;
    if (head == NULL)
    {
        printf("List is empty. Deletion not possible.\n");
    }
    else if (head->next == NULL)
    { // Only one node gfd
        free(head);
        head = NULL;
    }
    else
    {
        tail = head;
        while (tail->next->next != NULL)
        { // Find second last node
            tail = tail->next;
        }
        free(tail->next);
        tail->next = NULL;
    }
}

void delMiddle(){
    int pos, count = 1;
    printf("Enter the position of the node that needs to be deleted: ");
    scanf("%d", &pos);
    if (pos > getlength())
        printf("invalid position\n");
    else
    {
        if (head == NULL)
        {
            printf("List is empty. Deletion not possible.\n");
        }
        else
        {
            ll nextnode = head;
            tail = head;
            while (count < pos - 1)
            {
                tail = tail->next; // up to prev of required node
                count++;
            }

            nextnode = tail->next;
            tail->next = nextnode->next;
            free(nextnode);
        }
    }
}
void reverseLinkedList()
{
    ll prevnode, currnode, nextnode;
    prevnode = 0;
    currnode = nextnode = head;
    while (nextnode != 0)
    {
        nextnode = nextnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    head = prevnode;
}
void freeList()
{
    ll temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp); // Free each node to prevent memory leaks
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("linked list operation\n");
        printf("1.Create\n");
        printf("2.Insert at Beginning\n");
        printf("3.Insert at End\n");
        printf("4.Insert at Middle\n");
        printf("5.Delete at Beginning\n");
        printf("6.Delete at End\n");
        printf("7.Delete at Middle\n");
        printf("8.Traverse\n");
        printf("9.Reverse linked list\n");
        printf("10.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            insBeg();
            break;
        case 3:
            insEnd();
            break;
        case 4:
            insMiddle();
            break;
        case 5:
            delBeg();
            break;
        case 6:
            delEnd();
            break;
        case 7:
            delMiddle();
            break;
        case 8:
            traverse();
            break;
        case 9:
            reverseLinkedList();
            break;
        case 10:
            exit(10);
        }
    }
    freeList(); // Free the allocated memory
    printf("linked list deallocated\n");
    return 0;
}