#include<stdio.h>
int min,max,arr[50];
void recursiveminmax(int i,int j)
{
    int max1,min1,mid;
    if(i==j)
    {
        min=arr[i];
        max=arr[i];
    }       
    else if (i==j-1)
    {
        if(arr[i]<arr[j])
        {
            min=arr[i];
            max=arr[j];
        }
        else
        {
            min=arr[j];
            max=arr[i];
        }
        
    }
    else
    {
        mid=(i+j)/2;
        recursiveminmax(i,mid);
        max1=max;
        min1=min;
        recursiveminmax(mid+1,j);
        if (max<max1)
            max=max1;
        if(min>min1)
            min=min1;
    }  
}
int main()
{
    int n;
    printf("Enter how many elements to enter: ");
    scanf("%d",&n);
    printf("Enter the elements:");
    for (int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    min=arr[0];
    max=arr[0];
    recursiveminmax(1,n);
    printf("MIN :%d , MAX: %d",min,max);
    
}
