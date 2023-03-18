#include<stdio.h>
#include<stdlib.h>

int *ptr , m;
 void creat()
 {    
     if(ptr!=NULL)
     {
         printf("you already created the array please select correct option from list \n ");
         return ;
     }
     else 
     printf("enter the numbers of elements you needed \n ");
     scanf("%d",&m);
     ptr=(int *)malloc(m*sizeof(int));
     if(ptr==NULL)
     {
         printf("space is not avaliable right now please try again");
         return;
     }
     else 
     printf("space succesfully allocated \n");
 }
 
 void input()
 {   int i=0;
     printf("enter elements of array\n"); 
 //printf("%d",m);
     /*for( i;i<m;i++)
        {
            scanf("%d",ptr+i);
        }*/
        while(i<m)
        {
            scanf("%d",(ptr+i));
            i++;
        }
     
 }
 void re()
 {   int temp=m;
     printf("enter the new size of array needed");
     scanf("%d",&m);
     ptr=(int *)realloc(ptr,m*sizeof(int));
     if(ptr==NULL)
     {
         printf("\n space not available \n");
     }
     else  
     printf("space granted \n");
  if(m>temp)
  {   printf("enter elements from %d",temp+1);
     for(int i=temp;i<m;i++)
     {
         scanf("%d",(ptr+i));
     }
      
  }
 }
 void disp()
 {
     for(int i=0;i<m;i++)
     {  
         printf("%d \n",*(ptr+i));
     }
 }
 
void main()
{     
     printf("\n welcome to dynamic memory menu based program \n");
     int m=0;
    while(1)
    {   int n;
       
        printf(" enter 1 for creating a dynamic arrya of integer \n");
        printf(" enter 2 for initilize array  values \n ");
        printf(" enter 3 for to increase or decrease the size of array \n");
        printf(" enter 4 for display the array elements \n");
        printf(" enter 5 for exit ");
        scanf("%d",&n);
        switch(n)
        {  case 1: creat();
                break;
            case 2: input();
                break;
            case 3: re();
                break;
            case 4: disp();
                break;
            case 5: free(ptr);
                   exit(0);
                   break;
            default : printf("pleace enter valid input from the list");
                
        
        }
    }
}
