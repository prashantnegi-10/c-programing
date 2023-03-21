#include<stdio.h>
#include<stdlib.h>
struct node 
{
  int data;
  struct node *link;
};
struct node *front=NULL,*rear=NULL;
void create()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node ));
    if(temp==NULL)
    {
        printf("\n space not available right now \n");
        return ;
    }
    printf("\n Enter first element of Queue \n");
    scanf("%d",&temp->data);
    front=temp;
    rear=temp;
    temp->link=NULL;
}
void insert()
{
    struct node *temp,*q=rear;
    temp=(struct node *)malloc(sizeof(struct node ));
    if(temp==NULL)
    {
        printf("\n space not available right now \n");
        return ;
    }
    printf("\n Enter data to be inserted in Queue \n");
    scanf("%d",&temp->data);
   // q=rear;
    q->link=temp;
    rear=temp;
    printf("\n Data inserted succesfully \n");
}
void del()
{  int l;
  struct node *temp;
    if(front==rear)
    {
        printf("\n Single element present in Queue \n you sure to delete enter 1 \n");
        scanf("%d",&l);
        if(l==1)
        { temp=front;
          front=NULL;
          rear=NULL;
          free(temp);
          printf("\n item deleted successfully \n ");
            return ;
        }
    }
    temp=front;
    front=front->link;
    free(temp);
      printf("\n item deleted successfully \n ");
}
void disp()
{
    struct node *temp;
    temp=front;
    while(temp!=NULL)
    {
        printf("# %d #",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void main()
{   int k;
    printf("----Wellcome to Queue program using Linked list -----\n");
    while(1)
    {  printf("Enter 1 for Creating Queue \n");
        printf("Enter 2 for Insert in Queue \n");
        printf("Enter 3 for Delete from Queuee \n");
        printf("Enter 4 for Display Queue \n");
        printf("Enter 5 for Exit \n");
        scanf("%d",&k);
        switch(k)
        {
            case 1: if(front==NULL)
                {    create();
                }
                else 
                { printf("\n You already created the Queue \n");
                }
                break;
            case 2: if(front==NULL)
                {
                    printf("\n please create the Queue first \n");
                }
                else 
                {  
                    insert();
                }
                break;
            case 3: if(front==NULL)
                {
                printf("\n Queue is Empty please create the Queue first \n");
                }
                else
                {
                del();
                }
                break;
            case 4: if(front==NULL)
                    {
                        printf("\n Queue is empty \n");
                    }
                    else
                    {
                        disp();
                    }
                    break;
            case 5: exit(0);
                    break;
            default: printf("\n please Enter valid input \n");
        }
    }
}
