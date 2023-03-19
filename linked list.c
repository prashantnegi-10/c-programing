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
       printf("\n space not  available right now \n");
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
    printf("enter the position where you want to insert item\n ");
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
         printf("\n position out of bound \n");
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
        printf("\n space not available right now\n");
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
     printf("\n item delete successfully\n");
    }
void del_item()
{
    int item;
    struct node *temp,*q;
    printf("enter item to be delete \n");
    scanf("%d",&item);
    temp=start;
    while(temp!=NULL)
    {
        if(temp->link->data==item)
       {
           q=temp->link;
          temp->link=q->link;
           free(q);
               printf("\n item delete successfully\n");
               return ;
       }
        temp=temp->link;
    }
  //  temp=temp->link->link;
    //free(temp);
 
}
void del_end()
{
    struct node *temp,*q;
    temp=start;
    while(temp->link!=NULL)
    {   q=temp;
        temp=temp->link;
    }
    q->link=NULL;
    free(temp);
    printf("\nitem deleted successfully \n");
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
void reverse()
{  struct node *q1,*q2,*q3;
    if(start==NULL)
    {
        printf("\n listed is empty :-)");
        return ;
    }
    q1=start;
    if(q1->link==NULL)
    {
        printf("list has only one element :-)");
        return ;
    }
    q2=q1->link;
    q3=q2->link;
    q1->link=NULL;
    q2->link=q1;
    while(q3->link!=NULL)
    {
        q1=q2;
        q2=q3;
        q3=q3->link;
        q2->link=q1;
    }
    start=q2;
    printf("\nlist is reverse successfully\n");
}
void main()
{   int n,data;
    while(1)
    {
        printf("Enter 1 for insertion in linked list\n");
        printf("Enter 2 for deletion in linked list \n");
        printf("Enter 3 for display list \n");
        printf("Enter 4 for reverse the linked list \n");
        printf("Enter 5 for exit from program\n");
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
                    scanf("%d",&l);
                    switch(l)
                         {
                             case 1: del_start();
                                break;
                            case 2:del_item();
                                break;
                            case 3:del_end();
                                break;
                            default: printf("\nenter the valid input \n");
                                break;
                        }
                    }
                    break;
            case 3: display();
                    break;
            case 4: reverse();
                    break;
            case 5 : exit(0);
                    break;
            default: printf("enter valid input\n");
            break;
                    
        }
    }
}
}
