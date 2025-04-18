#include<stdio.h>
float knapsack(int n,float weight[],float profit[],float m)
{
    float x[20],tp=0;
    int i,j;
    for(i=0;i<n;i++)
    x[i]=0.0;
    for(i=0;i<n;i++)
    {
        if(weight[i] > m)
        break;
    else{
        x[i]=1.0;
        tp=tp+profit[i];
        m=m-weight[i];

    }
    }
    if(i<n)
    x[i]=m/weight[i];
    tp=tp + (x[i]*profit[i]);
    printf("\n The result vector is :\n");
    for(i=0;i<n;i++)
    printf("\t %f",x[i]);
    printf("\n Maximun profit is: %f",tp);
    return tp;

}
void main()
{
    float weight[20],profit[20],capacity,max1,max2,max3;
    int n,i,j,num;
    float ratio[20],temp;
    printf("\n Enter the num of objects:\n");
    scanf("%d",&n);
    printf("\n Enter the weight of each objects:\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&weight[i]);
    }
    printf("\n Enter the profit of each objects:\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&profit[i]);
    }
    printf("\n Enter the capacity of knapsack:\n");
    scanf("%f",&capacity);

    //methaod 1
    printf("\n\n Method I select all ojjects in non decreasing order of there weights\n");
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(weight[i] > weight[j])
            {
                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;

                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;
            }
        }
    }
    max1 = knapsack(n,weight,profit,capacity);

    // Method 2

    printf("\n\n Method II select all ojjects in non increasing order of there profit\n");
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(profit[i] < profit[j])
            {
                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;

                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;
            }
        }
    }
    max2 = knapsack(n,weight,profit,capacity);

    //Method 3

    printf("\n\n Method III select all ojjects in non increasing order of ratio p/w \n");
    for(i=0;i<n;i++)
    {
        ratio[i]=profit[i]/weight[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ratio[i] < ratio[j])
            {
                temp=ratio[j];
                ratio[j]=ratio[i];
                ratio[i]=temp;

                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;

                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;

            }
        }
    }
    max3 = knapsack(n,weight,profit,capacity);

    if(max1 > max2 && max1> max3)
    printf("\n Optimal sol = %f",max1);
    else if(max2 > max1 && max2> max3)
    printf("\n Optimal sol = %f",max2);
    else
    printf("\n Optimal sol = %f",max3);
}
    





