#include <stdio.h>
int nonrecursivebinarysearch(int arr[50],int l,int h,int ele){
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]==ele)
            return mid;
        if(arr[mid]>ele)
            h=mid-1;
        else
            l=mid+1;
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
    int result=nonrecursivebinarysearch(arr,0,n-1,ele);
    if(result!=-1)
    printf("Element found at:%d",result);
    else
    printf("Element not found in array");
}