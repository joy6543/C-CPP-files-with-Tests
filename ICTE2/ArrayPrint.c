#include <stdio.h>
#include <stdlib.h>

void main()
{
    int len=0;
    int arr[15];
    int i;

    printf("Input the number of elements to store in the array (max 15):");
    scanf("%d", &len);

    printf("Input 5 number of elements in the array :\n");
    for(i=0; i<len; i++)
    {
        printf("element - %d:", i+1);
        scanf("%d", &arr[i]);
    }

    printf("The elements of array in reverse order are :\n");
    for(i=len-1; i>=0; i--)
    {
        
        printf("element - %d:%d ", i+1, arr[i]);
    }
    printf("\n");
    return;
}