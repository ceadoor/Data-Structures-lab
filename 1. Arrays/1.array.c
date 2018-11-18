/* 
    Author     : abhijithvijayan
    Title      : Arrays
*/

#include <stdio.h>
void main()
{
  int i, n, Ar[20];
  printf("Enter array size:");
  scanf("%d", &n);
  printf("Enter array elements\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &Ar[i]);
  }
  printf("The array elements are\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", Ar[i]);
  }
}