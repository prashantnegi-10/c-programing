#include<stdio.h>
#include<stdlib.h>

struct node
{  int data;
struct node *link;
};
struct node *top=NULL;
//top=NULL;
void create()
{   struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  if(temp==NULL)
  {
      printf("\n space is not available \n");
    return ;
  }
     printf("Enter data to insert \n");
     scanf("%d",&temp->data);
     top=temp;
     temp->link=NULL;
     printf("\nStack is created\n");
       
   }

void insert()
{   struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  if(temp==NULL)
  {
      printf("\n space is not available \n");
    return ;
  }
  else
  {      printf("Enter data to insert \n");
     scanf("%d",&temp->data);
     temp->link=top;
     top=temp;
     
  }
 printf("\n item PUSDED is Stack\n");
}

void del()
{
   struct node *temp;
   temp=top;
   top=temp->link;
   free(temp);
   printf("item POPED from Stack\n ");
}

void display()
{  struct node *temp=top;  
if(top==NULL)
{  printf("\n stck is empty :-) \n");
  return ;
 }
 while(temp!=NULL)
 {  printf("# %d # ",temp->data);
   temp=temp->link;
 }
 printf("\n");
}

void main()
{  int c;
printf("welcome to stack program using linked list \n");
   while(1)
   {  printf("Enter 1 for create Stack \n");
   printf("Enter 2 for PUSH in stack \n");
   printf("Enter 3 for POP \n");
   printf("Enter 4 for display \n");
   printf("Enter 5 for exit \n");
   scanf("%d",&c);
   switch(c)
   {
    case 1: if(top==NULL)
    {
create();
     }
     else{
       printf(" \n You already create the stack \n");
}

    break;
    case 2: insert();
    break;
    case 3: del();
    break;
    case 4: display();
    break;
    case 5: exit(0);


    break;
    default : printf("\n enter valid input \n");
   }
   }
   
}

