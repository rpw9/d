#include<stdio.h>
#include<string.h>
int lcsLength(char *X,char *Y,int m,int n)
{
    int i,j;
    int dp[m+1][n+1];
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i == 0 || j == 0)
            dp[i][j]=0;
            else if(X[i-1] == Y[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=(dp[i-1][j]>dp[i][j-1]) ? dp[i-1][j]:dp[i][j-1];
        }
    }
    return dp[m][n];
}
int main()
{
    char X[100],Y[100];
    printf("Enter first string:\n");
    scanf("%s",X);
    printf("Enter second string:\n");
    scanf("%s",Y);
    int m=strlen(X);
    int n=strlen(Y);
    int length=lcsLength(X,Y,m,n);
    printf("Length of Longest Common Subsequence:%d\n",length);
    return 0;
}