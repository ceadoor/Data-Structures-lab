/* 
    Author     : abhijithvijayan
    Title      : Queue Operations
*/

#include <stdio.h>
int Ar[25], n, front = -1, rear = -1, item;
void insert(int n);
void delete ();
void view();

void main()
{
  int n, ch;
  printf("Enter the size of Queue:");
  scanf("%d", &n);
  do
  {
    printf("\n----Operations Menu----\n\n1.Insert\n2.Delete\n3.Exit\n");
    printf("Enter the choice#:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      insert(n);
      break;
    case 2:
      delete ();
      break;
    default:
      break;
    }
  } while (ch < 3);
}

void insert(int n)
{
  if (rear >= n - 1)
  {
    printf("\n---Overflow!!!---\n\n");
  }
  else
  {
    if (front == -1 && rear == -1)
    {
      front++;
    }
    printf("Enter the element to be inserted:");
    scanf("%d", &item);
    rear++;
    Ar[rear] = item;
  }
  view(rear);
}

void delete ()
{
  if (front == -1)
  {
    printf("\n---Underflow!!!---\n\n");
  }
  else
  {
    item = Ar[front];
    printf("The element deleted is %d\n", item);
    if (front == rear)
    {
      front = -1;
      rear = -1;
      printf("\n---Oops the queue is empty---\n\n");
    }
    else
    {
      front++;
      view(rear);
    }
  }
}

void view(int rear)
{
  int i;
  printf("\nThe current Queue is\n");
  for (i = front; i <= rear; i++)
  {
    printf("%d ", Ar[i]);
  }
  printf("\n");
}
