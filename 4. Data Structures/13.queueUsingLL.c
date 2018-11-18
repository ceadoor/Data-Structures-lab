#include <stdio.h>
#include <stdlib.h>
int item;
void view();

struct Node
{
  int data;
  struct Node *link;
};

struct Node *front;
struct Node *rear;

int userInput()
{
  printf("Enter the number:");
  scanf("%d", &item);
  return item;
}

void enQueue()
{
  item = userInput();
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = item;
  temp->link = NULL;
  if (front == NULL && rear == NULL)

    front = rear = temp;

  else
  {
    rear->link = temp;
    rear = temp;
  }
  view();
}

int deQueue()
{
  struct Node *newptr = front;
  if (front == NULL && rear == NULL)
  {
    printf("The queue is already empty!! Underflow\n");
    return 0;
  }
  else if (front == rear)
  {
    front = NULL;
    rear = NULL;
  }
  else
  {
    front = front->link;
  }
  free(newptr);
  view();
}

int isEmpty()
{
  if (front == NULL && rear == NULL)
    return 1;
  return 0;
}

void view()
{
  printf("\nThe Queue is\n");
  if (!isEmpty())
  {
    struct Node *newptr = front;
    while (newptr != NULL)
    {
      printf("%d ", newptr->data);
      newptr = newptr->link;
    }
    printf("\n\n");
  }
  else
    printf("----EMPTY----\n");
}

void main()
{
  system("clear");
  front = NULL;
  rear = NULL;
  int ch;
  do
  {
    printf("\n---Operations Menu---\n");
    printf("1.Insert\n2.Delete\n\nEnter your choice# ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      enQueue();
      break;
    case 2:
      deQueue();
      break;
    }
  } while (ch < 3);
}
