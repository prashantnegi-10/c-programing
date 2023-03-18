#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
struct node *start=NULL;
void insert_front(int data)
{  struct node *temp;
   temp=(struct node *)malloc(sizeof(struct node));
   if(temp==NULL)
   {
       printf("\n space not avaliable right now \n");
       return ;
   }
    printf("\n enter to be insert in fornt \n");
        scanf("%d",&data);
        temp->data=data;
        temp->link=NULL;
        if(start==NULL)
        {
            start=temp;
        }
        else {
              temp->link=start;
              start=temp;
        }
}
void insert_mid()
{   int data,pos,t;
    struct node * temp,*q,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n memory not available right now \n");
        return ;
    }
    if(start==NULL)
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
    { 
        q=p;
        p=p->link;
     if(p->link==NULL)
     {
         printf("\n postion out of bound \n");
         return ;
     }
    }
   // q=p->link;
   q->link=temp;
    //p->link=temp;
    temp->link=p;
    //temp->link=q;
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
    else 
    if(start==NULL)
    {
        printf("\nlist is empty \n");
        printf(" do you want to insert data at first enter 1 \n");
        scanf("%d",&n);
        if(n==1)
        {   printf("enter value to insert \n");
            scanf("%d",&data);
            temp->data=data;
            start=temp;
        }
        return ;
    }
    p=start;
    printf("enter data to be insert \n");
    scanf("%d",&data);
    temp->data=data;
    while(p->link!=NULL)
    {
        p=p->link;
    }
    p->link=temp;
}
void del_start()
{    struct node *temp;
    temp=start;
     start=start->link;
     free(temp);
     printf("\n item delete succesfully");
    }
void del_item()
{
    int item;
    struct node *temp;
    printf("enter item to be delete \n");
    scanf("%d",&item);
    temp=start;
    while(temp!=NULL)
    {
        if(item==temp->link->data)
        break;
        temp=temp->link;
    }
    temp=temp->link->link;
    free(temp);
}
void del_end()
{
    struct node *temp;
    temp=start;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    free(temp);
    printf("item deleted succesfully\n");
}
void display()
{
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("# %d #",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void main()
{   int n,data;
    while(1)
    {
        printf("Enter 1 for insertion in linked list\n");
        printf("Enter 2 for deletion in linked list \n");
        printf("Enter 3 for display list \n");
        printf("Enter 4 for exit from program\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: int k;
                   { printf("\nenter 1 for insert in front of list\n");
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
            case 2: int l;
                     if(start==NULL)
                   {
                       printf("list is empty\n");
                       break;
                   }
                   else
                     {
                    printf("enter 1 for delete from start\n");
                    printf("enter 2 for delete a given item\n");
                    printf("enter 3 for delete from end \n");
                    switch(l)
                    {
                        case 1: del_start();
                                break;
                        case 2:del_item();
                                break;
                        case 3:del_end();
                                break;
                        default: printf("\nenter the valid input \n");
                    }
                    }
                    break;
            case 3: display();
                    break;
            case 4 : exit(0);
                    break;
            default: printf("enter valid input\n");
            break;
                    
        }
    }
}
}
