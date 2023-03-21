#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* last=NULL;

void create()
{  
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n Memory not available right now \n");
        return ;
    }
    printf("\n Enter first Element of Circular Linked list \n");
    scanf("%d",&temp->data);
    last=temp;
    temp->link=temp;
    printf("\n Circular created successfully \n");
}
void insert_first()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n Memory is not available right now \n");
          return ;
    }
    printf("\n Enter data ");
    scanf("%d",&temp->data);
    temp->link=last->link;
    last->link=temp;
    printf("\n data inserted successfully \n");
}
void insert_atposition()
{
    int pos,count;
    struct node *temp,*q;
    struct node *r;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n space is not avilable right now \n");
        return ;
    }
    printf("\n Enter position you cant to insert data \n");
    scanf("%d",&pos);
    if(pos<1)
    {
        printf("\n position will be greater than 1 \n ");
        return ;
    }
    q=last->link;
    while(q!=last)
    {
        count++;
        q=q->link;
    }
    if(count>pos)
    {
        printf("\n position out of bound \n");
        return  ;
    }
    printf("\n Enter data to be insert \n");
    scanf("%d",&temp->data);
    for(int i=1;i<=pos;i++)
    { q=q->link;
    }
    temp->link=q->link;
    q->link=temp;
    printf("\n Data inserted in successfully \n");
}
void insert_after()
{
    int value,pos=0,i=1;
    struct node *temp,*q;
    printf("Enter value after which you want insert data \n");
    scanf("%d",&value);
    q=last->link;
    while(q->link!=last)
    {
        if(q->data==value)
        {
            pos=i;
            break;
        }
        i++;
        q=q->link;
    }
    if(pos==0)
    {
        printf("\n %d is not present in Circular Linked list\n",value);
        return ;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==0)
    {
        printf("\n Memory not available right now \n");
        return ;
    }
    printf("\n Enter data to be inserted ");
    scanf("%d",&temp->data);
    temp->link=q->link;
    q->link=temp;
    printf("\n item inserted successfully \n");
}
void insert_end()
{
    struct node *temp;
    temp=(struct node)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n Memory not availabe right now \n");
        return ;
    }
    printf("\n Enter data to be inserted  ");
    scanf("%d",&temp->data);
    temp->link=last->link;
    last->link=temp;
    last=temp;
    printf("\n data inserted successfully \n");
}
void main()
{  int k;
  printf("---Circular Linked List---\n");
    while(1)
    { printf("Enter 1 for Creating the Circular Linked list\n");
     printf("Enter 2 for Inserting data in Circular list \n");
     printf("Enter 3 for Deleting data from Circular list \n");
     printf("Enter 4 for Dispaly Circular list \n");
     printf("Enter 5 for Exit \n");
     scanf("%d",&k);
     switch(k)
     {
         case 1: if(last==NULL)
                {
                    create();
                }
                else
                    {
                        printf("\n You already created the Circular Linked list\n");
                    }
                    break;
         case 2: int l;
                    if(last==NULL)
                    {
                        printf("\n please create the Circular Linked list first \n");
                    }
                    else
                    { printf("\n Enter 1 for insert at first\n");
                      printf(" Enter 2 for insert at specific position\n");
                      printf("Enter 3 for insert after some value in Linked list \n");
                      printf("Enter 4 for insert at End \n");
                      scanf("%d",&l);
                      switch(l)
                      {
                          case 1: insert_first();
                                   break;
                          case 2: insert_atposition();
                                    break;
                          case 3: insert_after();
                                    break;
                          case 4: insert_end();
                                    break;
                          default: printf("\n Enter valid Input \n");
                      }
                    }
                    break;
                    break;
         case 3: int p;
                if(last==NULL)
                {
                    printf("\n please create the Circular Linked list first");
                }
                else 
                {
                    printf("\n Enter 1 for delete from first \n");
                    printf(" Entre 2 for delete from specific position \n");
                    printf("Enter 3 for delete specific value \n");
                    printf("Enter 4 for delete from End \n");
                    scanf("%d",&p);
                    switch(p)
                    {
                        
                    }
                }
     }
    }
}
