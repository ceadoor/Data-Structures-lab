/* 
    Author     : abhijithvijayan
    Title      : Linked List Operations
*/

#include <stdio.h>
#include <stdlib.h>
int n;
void insertAtbeg();
void insertAtend();
int insertAtpos();
void deleteAtbeg();
void deleteAtend();
int deleteAtpos();
int userPosInput();
int userInput();
int isInvalidpos(int pos, int ch);
void view();
int item;
struct Node
{
  int data;
  struct Node *link;
};

struct Node *headptr;
void main()
{
  system("clear");
  headptr = NULL;
  int i, item, ch;
  do
  {
    printf("\n---Operations Menu---\n\n");
    printf("1.Insertion at Beginning\n2.Insertion at End\n3.Insertion at specific position\n");
    printf("4.Deletion at Beginning\n5.Deletion at End\n6.Deletion at specific position\n");
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      insertAtbeg();
      view();
      break;
    case 2:
      insertAtend();
      view();
      break;
    case 3:
      insertAtpos();
      view();
      break;
    case 4:
      deleteAtbeg();
      view();
      break;
    case 5:
      deleteAtend();
      view();
      break;
    case 6:
      deleteAtpos();
      view();
      break;
    }
  } while (ch <= 6);
}

int userInput()
{
  printf("Enter the number:");
  scanf("%d", &item);
  return item;
}

int userPosInput()
{
  int pos;
  printf("Enter the position:");
  scanf("%d", &pos);
  return pos;
}

void insertAtbeg()
{
  item = userInput();
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = item;
  temp->link = headptr; /* Make link of new node as headptr */
  headptr = temp;       /* move the headptr to point to the new node */
}

void insertAtend() //if list is empty, the headptr->new node created
{
  item = userInput();
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = item;
  temp->link = NULL;
  if (headptr == NULL) /*if list is empty, point the headptr->new node created*/
    headptr = temp;
  else /* traverse with the help of another pointer till the last node */
  {
    struct Node *newptr = headptr; /* newptr will be another pointer pointing to 1st node(add in headptr stores to newptr)*/
    while (newptr->link != NULL)   /* for finding if the link part is NULL(end)*/
    {
      newptr = newptr->link;
    }
    newptr->link = temp; /* change the link of last node to the newly inserted node*/
  }
}

int isInvalidpos(int pos, int ch)
{
  int n = 0;
  struct Node *newptr = headptr;
  if (headptr != NULL)
  {
    while (newptr->link != NULL)
    {
      n++;
      newptr = newptr->link;
    }
    ++n; //n gets the total no of elements in the list
  }
  switch (ch)
  {
  case 1:
    if (pos > (n + 1) || pos == 0)
    {
      printf("\nInvalid position!!!\n");
      return 1;
    }

  case 2:
    if (pos >= (n + 1) || pos == 0)
    {
      printf("\nInvalid position!!!\n");
      return 1;
    }
  }
  return 0; //get executed even if 1st if false
}

int insertAtpos()
{
  int i;
  item = userInput();
  int pos = userPosInput();
  if (!isInvalidpos(pos, 1))
  {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); //create new node
    temp->data = item;
    if (pos == 1)
    { /* follow insertion at beginning */
      temp->link = headptr;
      headptr = temp;
    }
    else
    {
      struct Node *newptr = headptr; //address of headptr is stored to newptr
      for (i = 0; i < pos - 2; i++)  /* CAREFUL!! finding the node before the pos entered*/
      {
        newptr = newptr->link;
      }                          /* now at (n-1)th position */
      temp->link = newptr->link; /*take the address of the (n-1) node and copy to new node(link btw next node and new node created)*/
      newptr->link = temp;       /* make link btw (n-1) node and new node inserted*/
    }
  }
  else
    return 0;
}

void deleteAtbeg()
{
  struct Node *newptr = headptr;
  if (headptr == NULL)
  {
    printf("\nUnderflow!!!\n");
  }
  else
  {
    headptr = newptr->link;
    free(newptr);
  }
}

void deleteAtend()
{
  if (headptr == NULL) // no element
  {
    printf("\nUnderflow!!!\n");
  }
  else
  {
    struct Node *newptr = headptr;
    if (newptr->link == NULL) /* Only one element */
    {
      headptr = NULL;
      free(newptr); //deleted the only node
    }
    else
    {
      struct Node *ptr;
      while (newptr->link != NULL)
      {
        ptr = newptr; // newptr will precede ptr
        newptr = newptr->link;
      }
      ptr->link = NULL;
      free(newptr);
    }
  }
}

int deleteAtpos()
{
  int i;
  int pos = userPosInput();
  if (!isInvalidpos(pos, 2))
  {
    struct Node *newptr = headptr;
    if (pos == 1)
    {
      headptr = newptr->link;
      free(newptr);
    }
    else
    {
      for (i = 0; i < pos - 2; i++)
      {
        newptr = newptr->link;
      } /*now newptr points to the (n-1)th node*/

      struct Node *ptr = newptr->link; //ptr now points to the nth node
      newptr->link = ptr->link;        /* link of newptr((n-1)th) is replaced with link of ptr(nth)=>link is created */
      free(ptr);                       //freed the nth node memory
    }
  }
  else
    return 0;
}

void view()
{
  printf("\nThe list is...\n");
  if (headptr == NULL)
    printf("----EMPTY----\n");
  else
  {
    struct Node *newptr = headptr;
    while (newptr != NULL) //careful
    {
      printf("%d ", newptr->data);
      newptr = newptr->link;
    }
    printf("\n\n");
  }
}
