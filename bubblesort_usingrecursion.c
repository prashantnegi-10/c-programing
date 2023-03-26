#include "stdbool.h"
#include<stdio.h>
void bubblesort(int arr[],int n)
{
    bool sorted=true;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            sorted=false;
        }
    }
    if(sorted==false)
    bubblesort(arr,n-1);
}
void main()
{
    int ar[]={5,4,8,2,9,7,3,1,6};
    int n=sizeof(ar)/sizeof(int);
    bubblesort(ar,n);
    printf("sorted array \n");
    for(int i=0;i<n;i++)
    {
    printf("# %d #",ar[i]);
}
}
