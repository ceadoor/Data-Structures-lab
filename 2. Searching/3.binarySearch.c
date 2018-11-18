#include <stdio.h>
void main()
{
  int i, n, Ar[20], var, top, bottom, mid, flag = 0;
  printf("Enter array size:");
  scanf("%d", &n);
  printf("Enter array elements\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &Ar[i]);
  }
  printf("Enter the element to be searched for:");
  scanf("%d", &var);
  top = 0;
  bottom = n - 1;
  while (top <= bottom)
  {
    mid = (top + bottom) / 2;
    if (var == Ar[mid])
    {
      printf("Element found at %d position", mid + 1);
      flag = 1;
      break;
    }
    else if (var > Ar[mid])
    {
      top = mid + 1;
    }
    else
      bottom = mid - 1;
  }
  if (flag == 0)
    printf("Element not found!!!!");
}
