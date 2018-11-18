#include<stdio.h>
int n,Ar[20];
void view();

void Isort()
{
  int i,j,key,temp;
  for(i=1;i<n;i++)
  {
    key=Ar[i];
    j=i-1;
   while(j>=0 && Ar[j]>key)
    {
      temp=Ar[j];
      Ar[j]=Ar[j+1];
      Ar[j+1]=temp;
      j--;
    }
  }
}

void insert()
{ int i;
  printf("Enter array elements\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&Ar[i]);
  }
}

void view()
{ int i;
  printf("The Sorted Array is\n");
  for(i=0;i<n;i++)
  {
    printf("%d ",Ar[i]);
  }
  printf("\n");
}

void main()
{
  printf("Enter array size:");
  scanf("%d",&n);
  insert();
  Isort();
  view();
}
