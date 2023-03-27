#include<stdio.h>
void main()
{
    int nums[]={1,1,2,2,3,3,4,4,5,6,6,7,7};
    int temp,n=sizeof(nums)/sizeof(int),count;
    for(int i=0;i<n-1;i++)
    {  temp=nums[i];
    count=0;
        for(int j=0;j<n-1;j++)
        {  if(nums[i]==nums[j])
        count++;
        }
        if(count==1)
        {
            printf("number is finded that apppear single time in array %d",nums[i]);
            break;
        }
    }
    if(count==2)
    printf("\n all number appear twice or more ");
}
