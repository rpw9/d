#include <stdio.h>
int main(void)
{
    int n, i, j, minIndex, temp;
    int arr[64];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n - 1; i++) 
    {
        minIndex = i; // Assume the minimum is the first element
        for (j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }
        // Swap the found minimum element with the first element
        if (minIndex != i)
        {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    printf("Sorted list in ascending order:\n");
    for (i = 0; i < n; i++) 
    {
        printf("\t%d", arr[i]);
    }
    return 0;
}
