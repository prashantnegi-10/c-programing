#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
struct node *start=NULL;
void create()
{   struct node *temp;
     temp=(struct node *)malloc(sizeof(struct node));
     if(temp==NULL)
     {
         printf("Memory not available right now \n");
         return ;
     }
     else 
    printf("Enter the First Element of the linked list \n");
    scanf("%d",&temp->data);
    start=temp;
    printf("First Element of linked inserted\n");
}
void insert_front()
{  
    int data;
    struct node *temp;
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
{   int data,pos,t,count=1;
  printf("enter the position where you want to insert item\n ");
    scanf("%d",&pos);
    struct node *kount=start;
    while(kount!=NULL)
  // for(kount=start;kount->link!=NULL;kount=kount->link)
    {
        
        kount=kount->link;
        count++;
    }
  //  printf("%d",count);
    if(count<pos)
    {
        printf("Enter position out of bound please recheck using diplay functionality\n");
        return ;
    }
    else {
    struct node * temp,*q,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n memory not available right now \n");
        return ;
    }
    printf("\n enter data to be insert \n");
    scanf("%d",&data);
    temp->data=data;
    p=start;
    for(int i=1;i<pos;i++)
    { 
        q=p;
        p=p->link;
  /*   if(p->link==NULL)
     {
         printf("\n position out of bound \n");
         return ;
     }*/
    }
   // q=p->link;
   q->link=temp;
    //p->link=temp;
    temp->link=p;
    //temp->link=q;
}
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
void sort()
{
    struct node *q1;//*q2,*q3;
    struct node *q2;
    int temp;
   // struct node *q3;
    q1=start;
    //q2=q1->link;
   // for(;q1->link->link!=NULL;q1=q1->link)
   while(q1->link!=NULL)
    {   q2=q1->link;
        while(q2!=NULL)
       // for(;q2->link!=NULL;q2=q2->link)
        {
            if(q2->data<q1->data)
            {
                temp=q2->data;
                q2->data=q1->data;
                q1->data=temp;
            }
            q2=q2->link;
        }
        q1=q1->link;
      // q2=q2->link;
    }
    printf("list is sorted \n");
}
void main()
{   int n,data;
    while(1)
    {   printf("Enter 1 for creating in linkrd list\n");
        printf("Enter 2 for insertion in linked list\n");
        printf("Enter 3 for deletion in linked list \n");
        printf("Enter 4 for display list \n");
        printf("Enter 5 for reverse the linked list \n");
        printf("enter 6 for sorting thhe linked list \n");
        printf("Enter 7 for exit from program\n");
        scanf("%d",&n);
        switch(n)
        {    case 1: if(start!=NULL) 
                      {
                          printf("\nYou already created the linked list\n");
                        
                      }
                 else
                    create();
                    break;
            case 2: if(start==NULL)
                    {   int c;
                        printf("\n you not create linkde list ....do you want to create enter 1\n");
                        scanf("%d",&c);
                        if(c==1)
                        create();
                    }
                    else {
                    int k;
                   { printf("\nenter 1 for insert in front of list\n");
                    printf("enter 2 for insert at any postion \n");
                    printf("enter 3 for insert in end of list\n");
                    scanf("%d",&k);
                    switch(k)
                    {
                        case 1:  insert_front();
                                 break;
                        case 2: insert_mid();
                                break;
                        case 3: insert_end();
                                break;
                        default: printf("\n enter valid input \n ");
                   }
                   }
                    }
                    break;
            case 3: int l;
                     if(start==NULL)
                   {
                       printf("list is empty :-) \n");
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
            case 4: display();
                    break;
            case 5: reverse();
                    break;
            case 6:   if(start==NULL)
                   {
                       printf("\n list is empty :-) \n");
                       break;
                   }
                   else
                   if(start->link==NULL)
                   {
                       printf("list has only one element :-)\n");
                   }
                   else
                    sort();
                    break;
            case 7 : exit(0);
                    break;
            default: printf("enter valid input\n");
            break;
                    
        
    }
}
}
