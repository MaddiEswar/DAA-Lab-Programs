#include <stdio.h>
int linearsearch(int arr[50],int n,int ele){
    if(arr[i]==ele)
        return i;
    
    return -1;
}
int main(){
    int arr[50],n,ele;
    printf("Enter how many elements to enter: ");
    scanf("%d",&n);
    printf("Enter the elements:");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Element to find in array: ");
    scanf("%d",&ele);
    int result=linearsearch(arr,n,ele);
    if(result!=-1)
    printf("Element found at:%d",result);
    else
    printf("Element not found in array");
}
