#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int optimal_merge(int arr[], int n)
{
    int cost = 0;

    while (n > 1)
    {
        int min1 = INT_MAX, min2 = INT_MAX;
        int min1_idx = -1, min2_idx = -1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < min1)
            {
                min2 = min1;
                min2_idx = min1_idx;
                min1 = arr[i];
                min1_idx = i;
            }
            else if (arr[i] < min2)
            {
                min2 = arr[i];
                min2_idx = i;
            }
        }

        cost += min1 + min2;
        arr[min1_idx] = min1 + min2;
        arr[min2_idx] = arr[n - 1];
        n--;
    }

    return cost;
}

int main()
{
    int num;
    printf("Enter no of records: ");
    scanf("%d",&num);
    int arr[num] ;
    printf("Enter the records: ");
    for(int i=0;i<num;i++) 
        scanf("%d",&arr[i]);
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum cost of merging is %d\n", optimal_merge(arr, n));
    return 0;
}
