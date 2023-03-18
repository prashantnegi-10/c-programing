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
    p=start;
    for(int i=1;i<pos;i++)
    {  p=p->link;
     if(p->link==NULL)
     {
         printf("\n postion out of bound \n");
         return ;
     }
    }
    q=p->link;
    p->link=temp;
    temp->link=q;
}
void insert_end()
{   int n,data;
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n space not avaliable right now\n");
        return ;
    }
    if(start==NULL)
    {
        printf("\nlist is empty \n");
        printf(" do you want to insert data at first enter 1 \n");
        scanf("%d",&n);
        if(n===1)
        {   printf("enter value to insert \n");
            scanf("%d",&data);
            temp->data=data;
            start=temp;
        }
    }
    p=start;
    while(p->link!=NULL)
    {
        p->link=p->link;
    }
    p->link=temp;
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
                                break;
                        case 3: insert_end();
                                break;
                        default: printf("\n enter valid input \n ");
                    }
                    break;
            case 2: 
        }
    }
}
