#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *create (struct node *top )
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n Memory not available right now \n ");
    }
    else 
    {  printf(" \nEnter data  ");
       scanf("%d",&temp->data);
       temp->link=NULL;
       top=temp;
       printf("\n Stack created successfully \n");
       return top;
    }
}
struct node *push(struct node *top)
{ 
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n Memory not available right now \n");
    }
    else
    {
        printf("Enter data to insert/Push ");
        scanf("%d",&temp->data);
        temp->link=top;
        top=temp;
        printf("\n data Pushed/inserted successfully \n");
        return top;
    }
}
struct node *pop(struct node *top)
{
    struct node *temp;
    temp=top;
    top=top->link;
    free(temp);
    printf("\n Data POPED/Deleted successfully\n");
    return top;
}
struct node *disp(struct node *top)
{
    struct node *temp=top;
    while(temp!=NULL)
    {
        printf("# %d #",temp->data);
        temp=temp->link;
    }

}
void main()
{
    struct node *top=NULL;
    int n;
    printf("---Welcome to stack program---");
    while(1)
    {
        printf("\n Enter 1 for create Stack \n");
        printf(" Enter 2 for inserting in Stack \n");
        printf(" Enter 3 for Delete data from Stack \n");
        printf("Enter 4 for Display\n");
        printf("Enter 5 for Exit \n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: if(top!=NULL)
                    {
                        printf("\n You Already created the Stack \n");
                    }
                    else
                    {
                        top=create(top);
                    }
                    break;
             case 2: if(top==NULL)
                    {
                        printf("\n Please Create the Stack first \n");
                    }
                    else
                    {
                        top=push(top);
                    }
                    break;
             case 3:  if(top==NULL)
                    {
                        printf("\n Stack underflow . Please Create the Stack  \n");
                    }
                    else
                    {
                        top=pop(top);
                    }
                    break;
             case 4: if(top==NULL)
                        {
                            printf("\n Stack underflow . Please Create the Stack  \n");
                        }
                        else 
                        {
                            disp(top);
                        }
                        break;
             case 5:  exit(0);
             break;
             default : printf("\n Please Enter valid input \n");
        }
    }
}
