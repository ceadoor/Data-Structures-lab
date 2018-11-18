/* 
    Author     : abhijithvijayan
    Title      : Linear Search
*/

#include <stdio.h>
void main()
{
    int i, n, Ar[20], var, sum;
    printf("Enter array size:");
    scanf("%d", &n);
    printf("Enter array elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &Ar[i]);
    }
    printf("Enter the element to be searched for:");
    scanf("%d", &var);
    for (i = 0; i < n; i++)
    {
        if (Ar[i] == var)
        {
            printf("Element found at %d position\n", i + 1);
            sum = 1;
        }
    }
    if (sum != 1)
    {
        printf("Element not found!!!!!!!");
    }
}