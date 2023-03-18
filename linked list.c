#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
struct node *start==NULL;
void insert_front(int data)
{  struct node *temp;
    int data;
   temp=(struct node *)malloc(sizeof(struct node));
   if(temp==NULL)
   {
       printf("\n space not avaliable right now \n");
       return ;
   }
    printf("\nenter to be insert in fornt \n");
        scanf("%d",&data);
        temp->data=data;
        temp->link=NULL;
        if(start==null)
        {
            start=temp;
        }
        else {
              temp->link=start;
              start=temp;
        }
}
insert_mid()
{   int data,pos,t;
    struct node * temp,*q,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n memory not available right now \n");
        return ;
    }
    if(start==null)
    {
        printf("list is empty \n do you want to insert item at first enter 1 \n");
        scanf("%d",&t);
        if(t==1)
        { printf("\n enter the data item \n ");
          scanf("%d",&data);
          temp->data=data;
          start=temp;
        }
        else 
            return ;
    }
    printf("enter the postion where you want to insert item\n ");
    scanf("%d",&pos);
    printf("\n enter data to be insert \n");
    scanf("%d",&data);
    temp->data=data;
    
    
    
}
void main()
{   int n,data;
    while(1)
    {
        printf("Enter 1 for insertion in linked list\n");
        printf("Enter 2 for deletion in linked list \n");
        printf("Enter 3 for display list \n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: int k;
                    printf("\nenter 1 for insert in front of list\n");
                    printf("enter 2 for insert at any postion \n");
                    printf("enter 3 for insert in end of list\n");
                    scanf("%d",&k);
                    switch(k)
                    {
                        case 1:  insert_front(data);
                                 break;
                        case 2: insert_mid();
                    }
        }
    }
}
