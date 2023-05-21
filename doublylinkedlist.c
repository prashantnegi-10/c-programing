#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *last=NULL;
void creat()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n Memory not avaliable right now ");
        return ;
    }
    printf("\n Enter data to insert ");
    scanf("%d",&temp->data);
    start=temp;
    last=temp;
    temp->prev=NULL;
    temp->next=NULL;
}
void insrtbeg()
{ struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n Memory not avaliable right now ");
        return ;
    }
    printf("\nEnter data");
    scanf("%d",&temp->data);
    temp->next=start;
    start->prev=temp;
    temp->prev=NULL;
    start=temp;
    printf("\n Data inserted successfuly");
    
}
void insrtpos()
{  int pos,count=0;
    struct node *q;
    q=start;
    printf("\n Enter the position where you want to insert the data");
    scanf("%d",&pos);
    while(q!=NULL)
    {
        count++;
        q=q->next;
    }
    if(pos>count)
    {
        printf("\n Position out of bound");
        return ;
    }
      if(pos==1)
    {
        insrtbeg();
        return ;
    }
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n Memory not avaliable right now ");
        return ;
    }
    printf("\nEnter data  ");
    scanf("%d",&temp->data);
    q=start;
    for(int i=1;i<pos;i++)
    {
        q=q->next;
    }
    temp->prev=q->prev;
    temp->next=q;
    q->prev->next=temp;
    printf("\n %d --%d--%d",q->data,temp->data,q->prev->data);
}
void insrtspec()
{
    int t,count=1,flag=0,l;
    printf("\n Enter the data element after which you want to insert ");
    scanf("%d",&t);
    struct node *q=start;
    while(q!=NULL)
    {
        if(q->data==t)
        {   flag=1;
            break;
        }
        count++;
        q=q->next;
    }
    if(flag==0)
    {
        printf("\n Entered element not present in linked list");
        return ;
    }
    printf("\n Enter 1 if you want to insert before the %d this",q->data);
    printf("\n Enter 2 if you want to insert after the %d this",q->data);
    scanf("%d",&l);
      struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n Memory not avaliable right now ");
        return ;
    }
    if(l==1)
    {    printf("\nEnter data");
    scanf("%d",&temp->data);
    q=start;
    for(int i=1;i<=count;i++)
    {
        q=q->next;
    }
  
    
    temp->prev=q->prev;
    temp->next=q;
    q->prev=temp;
   
    }
    else
    if(l==2)
    {       printf("\nEnter data");
    scanf("%d",&temp->data);
    q=start;
     for(int i=1;i<=count+1;i++)
    {
        q=q->next;
    }
  
    
    temp->prev=q->prev;
    temp->next=q;
    q->prev=temp;

    }
    else
    {
        printf("\n You selected wrong choise");
    
    }
        return;
    
    
}
void instlast()
{    struct node *temp,*q;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n Memory not avaliable right now ");
        return ;
    }
    printf("\nEnter data");
    scanf("%d",&temp->data);
    q=start;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=temp;
    temp->prev=q;
    temp->next=NULL;
}
void delbeg()
{
    struct node *q=start;
    start=q->next;
    start->prev=NULL;
    free(q);
}
void delpos()
{
    int pos,count=0;
    struct node *q,*p;
    q=start;
    printf("\n Enter the position where you want to delete the data");
    scanf("%d",&pos);
    while(q!=NULL)
    {
        count++;
        q=q->next;
    }
    if(pos>count)
    {
        printf("\n Position out of bound");
        return ;
    }
      if(pos==1)
    {
        delbeg();
        return ;
    }
    q=start->next;
    p=start;
    for(int i=1;i<pos-1;i++)
    {
        q=q->next;
    }
  p->next=q->next;
  q->next->prev=p;
  free(q);
  if(p->next==NULL)
  last=p;
}
void delspe()
{
    int t,count=1,flag=0;
    printf("\n Enter the data element which you want to delete ");
    scanf("%d",&t);
    struct node *q=start,*p;
    while(q!=NULL)
    {
        if(q->data==t)
        {   flag=1;
            break;
        }
        count++;
        q=q->next;
    }
    if(flag==0)
    {
        printf("\n Entered element not present in linked list");
        return ;
    }
   if(q->prev==NULL)
   {    delbeg();
       return ;
   }
   if(q->next==NULL)
   {   dellast();
       return ;
   }
   p=q->prev;
   p->next=q->next;
   q->next->prev=p;
   free(q);
}

void dellast()
{    struct node *temp,*q;
    q=start;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    temp=q->prev;
    temp->next=NULL;
    free(q);
  last=temp;
}
void  disp()
{
    struct node *q=start;
    while(q!=NULL)
    {
        printf("#%d#",q->data);
        q=q->next;
    }
}
void main()
{
    int k;
    printf("Doubly linked list program");
    while(1)
    {
        printf("\n Enter 1 for creating doubly linked listed ");
        printf("\n Enter 2 for insertion ");
        printf("\n Enter 3 for Deletion ");
        printf("\n Enter 4 for display");
        printf("\n Enter 5 for exit ");
        scanf("%d",&k);
        switch(k)
        {
            case 1: if(start==NULL)
            {   creat();
                    break;
            }
            else{
                printf("\n You already created, please select other operation ");
                break;
            }
            case 2: 
                    if(start!=NULL)
                    {
                    int m;
                  printf("\n Enter 1 for insert at beginning ");
                  printf("\n Enter 2 for insert specfic position ");
                  printf("\n Enter 3 for inset after specific item");
                  printf("\n Enter 4 for insert at last");
                  scanf("%d",&m);
                  switch(m)
                  {  case 1: insrtbeg();
                            break;
                      case 2: insrtpos();
                            break;
                      case 3: insrtspec();
                              break;
                       case 4:instlast();
                              break;
                       default :
                       printf("\n You Entered wrong choise");
                       break;
                  }
                    }
                    else {
                        printf("\n Please first create the doubly linked list");
                    }
                    break;
                case 3: if(start!=NULL)
                {  int d;
                      printf("\n Enter 1 for deletion at beginning ");
                  printf("\n Enter 2 for deletion specfic position ");
                  printf("\n Enter 3 for deletion after specific item");
                  printf("\n Enter 4 for deletion at last");
                  scanf("%d",&d);
                  switch(d){
                      case 1:delbeg();
                            break;
                      case 2: delpos();
                             break;
                      case 3:delspe();
                             break;
                      case 4: dellast();
                                 break;
                      default : printf("\n You Entered wrong choice");
                         break;
                  }
                    
                }
                else
                printf("\n Please first create the list");
                break;
          case 4: disp();
                    break;
          case 5: exit(0);
                  break;
            }
        }
    }
