#include<stdio.h>
#include<stdlib.h>
int userInput();

struct Node
{
  int data;
  struct Node *link;
};

struct Node *top;

void push()
{
  int item=userInput();
  struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
  temp->data=item;
  temp->link=top;
  top=temp;
}

void pop()
{
  if(top==NULL)
  {
    printf("The Stack is already empty\n");
  }
  else
  {
    struct Node *newptr=top;
    top=newptr->link;
    free(newptr);
  }
}

void view()
{  if(top==NULL)
     printf("Empty List\n\n");
  else
  { struct Node *newptr=top;
    printf("\nThe list is...\n");
    while(newptr!=NULL)       //careful
    {
      printf("%d ",newptr->data);
      newptr=newptr->link;
    }
    printf("\n\n");
  }
}

int userInput()
{ int item;
  printf("Enter the element:");
  scanf("%d",&item);
  return item;
}

void main()
{ system("clear");
  int ch;
  top==NULL;
  do
  {
    printf("\n---Operations Menu---\n");
    printf("1.Push\n2.Pop\n\nEnter your choice# ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: push();
              view();
              break;
      case 2: pop();
              view();
              break;
    }
  }while(ch<3);
}
