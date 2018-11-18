#include <stdio.h>
int n, Ar[20];

void Ssort()
{
  int i, j, small, pos, temp;
  for (i = 0; i < n - 1; i++)
  {
    small = Ar[i];
    pos = i;
    for (j = i + 1; j < n; j++)
    {
      if (Ar[j] < small)
      {
        small = Ar[j];
        pos = j;
        temp = Ar[i];
        Ar[i] = Ar[j];
        Ar[j] = temp;
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
  Ssort();
  view();
}
