#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next; // 4 bytes for 32 bit compiler || 8 byte for 64 bit compiler
  struct node *prev;
};
struct node *head = NULL, *tail, *temp, *newnode;
void create()
{
  int n;
  printf("enter the number of node u want to create: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
      printf("memory allocation failed\n");
      return;
    }
    printf("enter the data%d: ", i + 1);
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
      head = tail = newnode;
    else
    {
      tail->next = newnode;
      newnode->prev = tail;
      tail = newnode;
    }
  }
}
void traverse()
{
  if (head == NULL)
  {
    printf("!!!!!linked list is empty!!!\n");
    return;
  }
  printf("data of linked list: ");
  temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
void insBeg()
{
  newnode = (struct node *)malloc(sizeof(struct node));
  if (newnode == NULL)
  {
    printf("memory allocation failed\n");
    return;
  }
  printf("enter the data: ");
  scanf("%d", &newnode->data);
  newnode->next = NULL;
  newnode->prev = NULL;
  if (head == NULL)
  {
    head = tail = newnode; // If list is empty, head is the same
  }
  else
  {
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
  }
}
void insEnd()
{
  newnode = (struct node *)malloc(sizeof(struct node));
  if (newnode == NULL)
  {
    printf("memory allocation failed \n");
    return;
  }
  printf("enter the data: ");
  scanf("%d", &newnode->data);
  newnode->next = NULL;
  newnode->prev = NULL;
  if (head == NULL)
    head = tail = newnode;
  else
  {
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
  }
}
int getlength()
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
void insMiddle()
{
  int pos;
  printf("enter the position after which u want to inset the node: ");
  scanf("%d", &pos);
  if (pos > getlength() || pos < 1)
  {
    printf("invalid position\n");
    return;
  }
  else if (pos == 1)
  {
    insBeg();
  }
  else
  {
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
      printf("memory allocation failed\n");
      return;
    }
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("enter the data: ");
    scanf("%d", &newnode->data);
    int count = 1;
    temp = head;
    while (count < pos - 1)
    {
      temp = temp->next;
      count++;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    newnode->next->prev = newnode;
    temp->next = newnode;
  }
}
void delBeg()
{
  if (getlength() > 0)
  {
    temp = head;
    head = head->next;
    head->prev = 0;
    free(temp);
  }
  else
  {
    printf("!!!!linked list is empty!!!!!\n");
  }
}
void delEnd()
{
  // temp = head;
  if (tail == NULL)
  {
    printf("!!!linked list is empty!!!\n");
  }
  else
  {

    temp = tail;
    if (tail->prev == NULL)
    { // Only one node in the list
      head = tail = NULL;
    }
    else
    {
      tail = tail->prev; // Move tail to the previous node
      tail->next = NULL; // Set the new tail's next to NULL
    }

    free(temp); // Free the old tail node
  }
}
void delMiddle()
{
  if (head == NULL)
  {
    printf("list is empty\n");
    return;
  }
  int pos;
  printf("enter the position u want to dlete: ");
  scanf("%d", &pos);
  if (pos > getlength() || pos < 1)
  {
    printf("!!!!invalid position or linkedlist is empty!!!\n");
  }
  else if (head->next == NULL)
  {
    temp = head;
    head = tail = NULL;
    free(temp);
  }
  else
  {
    int count = 1;
    temp = head;
    while (count < pos)
    {
      temp = temp->next;
      count++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
  }
}
void freeList()
{
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}
void reverseDoublyLinkedList()
{
  if (head == NULL)
    return; // Check if the list is empty
  temp = head;
  struct node *tempswap;

  while (temp != NULL)
  {
    tempswap = temp->next;
    temp->next = temp->prev;
    temp->prev = tempswap;

    temp = tempswap;
  }
  temp = head;
  head = tail;
  tail = temp;
}
int main()
{
  int ch;
  while (1)
  {
    printf("\nlinked list operation\n");
    printf("1.Create\n");
    printf("2.Insert at Beginning\n");
    printf("3.Insert at End\n");
    printf("4.Insert at Middle\n");
    printf("5.Delete at Beginning\n");
    printf("6.Delete at End\n");
    printf("7.Delete at Middle\n");
    printf("8.Traverse\n");
    printf("9.Reverse Doubly linked list\n");
    printf("10.exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    printf("\n");
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
      reverseDoublyLinkedList();
      break;
    case 10:
      exit(10);
    }
  }
  freeList(); // Free the allocated memory
  printf("linked list deallocated\n");
  return 0;
}