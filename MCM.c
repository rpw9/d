#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

// Function to find the minimum number of multiplications
int MatrixChainOrder(int p[], int n) 
{
    int m[n][n];
    int i, j, k, l, q;

    // Initialize the diagonal elements to 0
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // l is chain length
    for (l = 2; l < n; l++) 
    {
        for (i = 1; i < n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INF;
            for (k = i; k <= j - 1; k++) 
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    // m[1][n-1] contains the minimum number of multiplications
    return m[1][n - 1];
}

int main()
{
    // Array representing the dimensions of the matrices
    
    int n,arr[10],i,size;
    printf("\n Enter size n");
    scanf("%d",&size);
    printf("\n Enter matrix chain  elements");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);

    printf("Minimum number of multiplications is %d\n",
           MatrixChainOrder(arr, size));

    return 0;
}
