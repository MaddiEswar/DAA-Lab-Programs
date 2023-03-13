#include <stdio.h>
int binarysearch(int arr[50],int l,int r,int ele){
    if(r>=l){
        int mid=(l+r)/2;
        if(arr[mid]==ele){
            return mid;
        }
        if(arr[mid]>ele)
           return binarysearch(arr,l,mid-1,ele);
        else
           return binarysearch(arr,mid+1,r,ele);
    }
    return -1;
}
int main(){
    int arr[50],n,ele,index;
    printf("Enter how many elements to enter: ");
    scanf("%d",&n);
    printf("Enter the elements:");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Element to find in array: ");
    scanf("%d",&ele);
    int result=binarysearch(arr,0,n,ele);
    if(result!=-1)
    printf("Element found at:%d",result);
    else
    printf("Element not found in array");
}