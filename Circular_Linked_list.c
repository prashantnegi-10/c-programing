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
    int pos,count=1;
        printf("\n Enter position where you want  to insert data \n");
    scanf("%d",&pos);
   if(pos==1)
   {
    insert_first();
    return ;
   }
    struct node *temp,*q;
    struct node *r;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n space is not avilable right now \n");
        return ;
    }

    if(pos<=0)
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
    if(count<pos-1)
    {
        printf("\n position out of bound \n");
        return  ;
    }
 
    printf("\n Enter data to be insert \n");
    scanf("%d",&temp->data);
    r=last->link;
   //printf("%d\n",r->data);
   // for(int i=1;i<=pos;i++)
   int i=1;
   while(i<pos-1)
    { r=r->link;
    i++;
    }
    //printf("%d\n",r->data);
    temp->link=r->link;
    r->link=temp;
    printf("\n Data inserted in successfully \n");
}
void insert_after()
{
    int value,pos=0,i=1;
    struct node *temp,*q;
    printf("Enter value after which you want insert data \n");
    scanf("%d",&value);
    q=last->link;
    while(q!=last)
    {
        if(q->data==value)
        {
            pos=i;
            break;
        }
        i++;
        q=q->link;
    }
    //printf("%d \n",q->data);
    if(q->data==value)
    { insert_end();
     return ;
    }
    if(pos==0)
    {
        printf("\n %d is not present in Circular Linked list\n",value);
        return ;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
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
    temp=(struct node *)malloc(sizeof(struct node));
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
int check()
{ int check;
    struct node *temp;
    temp=last->link;
    if(temp==last)
    {
        printf("\n Single Element is present in Circular linked list \n do you want to delete Enter 1 ");
        scanf("%d",&check);
        if(check==1)
        {
            last=NULL;
            free(temp);
            printf("\n data deleted successfully returning to main menu \n");
            return 0 ;
        }
        else
        {
         printf("\n You chose not to delete return to main menu \n");
            return 0;
        }
        
    }
    return 1;
    
}
void del_first()
{  int a=check();
    if(a==0)
    {
        return ;
    }
    struct node *temp;
    temp=last->link;
    last->link=temp->link;
    free(temp);
    printf("\n data deleted successfully");
}
void del_pos()
{  
    int pos,count=0,a=check();
    if(a==0)
    {   
        return ;
    }
    struct node *temp;
      struct node *q;
    struct node *r;
    printf("\n Enter position At which you want to delete data \n");
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
   // printf("%d   %d\n",q->data,count);
    if(count<pos)
    {
        printf("\n position out of bound \n");
        return  ;
    }
    r=last->link;
    for(int i=1;i<pos-1;i++)
    { r=r->link;
    }
    //printf("%d\n",r->data);
    temp=r->link;
    r->link=temp->link;
    free(temp);
     printf("\n Data Deleted  successfully \n");
}
void del_spe()
{    int a=check();
    if(a==0)
    {
        return ;
    }
    int value,check=0;
    printf("\n Enter value which you want to delete \n");
    scanf("%d",&value);
    struct node *q,*r;
    q=last->link;
    r=last;
    while(q!=last)
    {   if(q->data==value)
            {  check=1;
                break;
            }
        q=q->link;
        r=r->link;
    }
    if(q->data==value)
    {
       del_end();
       return ;
    }
    if(check==0)
    {
        printf("\n %d value not present in list returning to main menu \n ");
        return ;
    }
    r->link=q->link;
    free(q);
    printf("\n data deleted successfully \n ");
}
void del_end()
{  int a=check();
    if(a==0)
    {
        return ;
    }
    struct node *temp,*r;
    temp=last;
    r=last->link;
    while(r!=last)
    {
        temp=temp->link;
        r=r->link;
    }
    temp->link=last->link;
    free(r);
    printf("\n data deleted successfully");
}
void  dis()
{  int val;
    struct node *temp=last->link;
    printf("# %d #",temp->data);
    val=temp->data;
    temp=temp->link;
    while(temp->data!=val)
    {
        printf("# %d #",temp->data);
        temp=temp->link;
    }
    printf("\n");
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
                    { case 1: del_first();
                                break;
                      case 2: del_pos();
                                break;
                      case 3: del_spe();
                                break;
                      case 4: del_end();
                                break;
                      default : printf("\n Enter valid Input \n");
                        }
                }
                        break;
         case 4: if(last==NULL)
                    {
                        printf("\n please create the Circular Linked list first");
                    }
                else 
                {
                    dis();
                }
                break;
         case 5: exit(0);
                 break;
         default : printf("\n Please Enter valid input \n");
                
                }
     }
    
}
