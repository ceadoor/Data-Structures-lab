#include <stdio.h>
int n, Ar[20];

void Bsort()
{
  int i, j, temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - 1 - i; j++)
    {
      if (Ar[j] > Ar[j + 1])
      {
        temp = Ar[j];
        Ar[j] = Ar[j + 1];
        Ar[j + 1] = temp;
      }
    }
  }
}

void insert()
{
  int i;
  printf("Enter array elements\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &Ar[i]);
  }
}

void view()
{
  int i;
  printf("The Sorted Array is\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", Ar[i]);
  }
}

void main()
{
  printf("Enter array size:");
  scanf("%d", &n);
  insert();
  Bsort();
  view();
}
