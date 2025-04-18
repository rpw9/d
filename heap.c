#include<stdio.h>
void heapify(int a[],int n,int i)
{
    int temp,max,lindex,rindex;
    max=i;
    rindex=2 * i + 2;
    lindex=2 * i + 2;
    if(lindex < n && a[lindex] > a[max])
        max=lindex;
    if(rindex < n && a[rindex] > a[max])
        max=rindex;
    if(max != i)
    {
        temp=a[i];
        a[i]=a[max];
        a[max]=temp;
        heapify(a,n,max);
    }
}
void heapSort(int a[], int n)
{
    int i,temp;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--) 
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}
int main()
{
    int a[20];
    int n,i;
    printf("\n Enter how many elements you want:");
    scanf("%d",&n);
    printf("\nEnter array elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nOriginal array: ");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    heapSort(a,n);
    printf("\nArray after heap sort:");
    for(int i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    return 0;
}