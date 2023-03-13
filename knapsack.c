#include<stdio.h>

void knapsack(int n,float m,float p[20],float w[20])
{
    int i,j,u;
    float profit=0,x[20];
    u=m;
    for(i=0;i<n;i++)
        x[i]=0.0;
    for(i=0;i<n;i++)
    {
        if(w[i]>u)
            break;
        else{
            x[i]=1.0;
            profit=profit+p[i];
            u=u-w[i];
        }
    }
    if(i<n)
        x[i]=u/w[i];
    profit=profit+(x[i]*p[i]);
    printf("Result array:");
    for(i=0;i<n;i++)
        printf("%f\t",x[i]);
    printf("\nProfit is %f",profit);

}
void main()
{
    float profit[20],weight[20],mass;
    int n;

    printf("Enter how many objects");
    scanf("%d",&n);
    printf("Enter the bag capacity:");
    scanf("%f",&mass);
    printf("Enter the profits:");
    for(int i=0;i<n;i++)
        scanf("%f",&profit[i]);
    printf("Enter the weights:");
    for(int i=0;i<n;i++)
        scanf("%f",&weight[i]);
    float pp[20],x[20],temp;
    for(int i=0;i<n;i++)
    {
        pp[i]=profit[i]/weight[i];
        
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(pp[i]<pp[j])
            {
                temp=pp[i];
                pp[i]=pp[j];
                pp[j]=temp;

                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;

                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;
            }
        }
    }
    knapsack(n,mass,profit,weight);

}