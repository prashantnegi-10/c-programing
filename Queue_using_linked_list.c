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
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n Space is not available right now \n");
        return ;
    }
    printf("\n Enter First element \n");
    scanf("%d",&temp->data);
    front=temp;
    rear=temp;
    printf("\n Queue is successfully created \n");
}
void insert()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n Space is not available right now \n");
         return ;
    }
    printf("\n Enter data to insert \n");
    scanf("%d",&temp->data);
    rear->link=temp;
    temp->link=NULL;
    rear=temp;
    printf("\n Data inserted successfully \n");
}
void del()
{  int k;
    struct node *temp;
    if(front==rear)
    {
        printf("\n Single element present in queue \n do you want to delete the queue Enter 1 \n");
        scanf("%d",&k);
        if(k==1)
        { temp=front;
         front=NULL;
         rear=NULL;
         free(temp);
         printf("\n Queue is deleted successfully returing tomain menu \n");
         return ;
        }
        else
        {
            return ;
        }
    }
    temp=front;
    front=temp->link;
    free(temp);
    printf("\n Data deleted successfully \n");
}
void show()
{
    struct node *temp;
    temp=front;
    while(temp!=rear)
    {
        printf("# %d #",temp->data);
        temp=temp->link;
    }
    printf("# %d #\n",temp->data);
    
}
void main()
{  int k;
    printf("---Welcome to Queue By Linked list---\n");
    while(1)
    {
        printf("Enter 1 for creating Queue \n");
        printf("Enter 2 for Inserting in Queue \n");
        printf("Enter 3 for Deleting in Queue \n");
        printf("Enter 4 for Display \n");
        printf("Enter 5 for Exit \n");
        scanf("%d",&k);
        switch(k)
        { case 1: if(front!=NULL)
                {
                    printf("\n you already created the Queue \n");
                }
                else 
                {
                    create();
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
                {    printf("\n please create the Queue first \n");
                    }
                  else 
                    {
                        del();
                    }
                    break;
          case 4: if(front==NULL)
                {    printf("\n please create the Queue first \n");
                    }
                    else 
                    {
                        show();
                    }
                    break;
         case 5: exit(0);
        }
    }
}
