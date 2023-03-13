#include <stdio.h>

int main(){
    int arr[50],n,min,max;
    printf("Enter how many elements to enter: ");
    scanf("%d",&n);
    printf("Enter the elements:");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    min=arr[0],max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(min>arr[i])
            min=arr[i];
        if(max<arr[i])
            max=arr[i];
    }
    printf("Min: %d , Max: %d",min,max);
}