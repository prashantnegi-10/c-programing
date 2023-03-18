#include<stdio.h>
#define MAX 5
int dq[MAX],front=-1,rear=-1;
void insert_end(int item)
{ 
  if(front==-1)
  {
      front=0;
      rear=0;
  }
else
if(rear==MAX-1)
 {
     rear=0;
 }
 else rear++;
   dq[rear]=item;
}
void insert_front(int item)
{
  if(front==-1)
  {
      front=0;
      rear=0;
  }
  else if(front==0)
  {
      front=MAX-1;
  }
  else front--;
   dq[front]=item;
}
void del_front()
{    int temp;
   temp=dq[front];
    if (front==rear)
    {
        front=-1;
    }
    if(front==MAX-1)
    {
        front=0;
    }
    else front++;
    printf("\nitem deleted\n");
    }
void del_end()
{    if(front==rear)
      {
          front==-1;
      }
else
    if(rear==0)
    {  rear=MAX-1;
    }
else rear--;
printf("\nitem deleted\n ");
}
void desp()
{   int i;
    if(front==-1)
    {
        printf("\nDqueue is empty \n");
        return ;
    }
    if (rear>front)
    {
        for( i=front;i<=rear;i++)
        printf("%d\n",dq[i]);
    }
    else 
   { for(i=front;i<=MAX-1;i++)
       printf("%d\n",dq[i]);
     for(i=0;i<=rear;i++)
       printf("%d\n",dq[i]);
     }
}

void main()
{    int n,item;
    printf("\n welcome to duble ended queue program \n");
    while(1)
    {
        printf("enter 1 for insert item in queue\n");
        printf("enter 2 for delete item for queue\n");
        printf("enter 3 for dipaly \n");
        printf("enter 4 for exit \n");
        scanf("%d",&n);
    switch(n)
    {
        case 1: int m;
                 if(rear==MAX-1 && front==0 || front==rear+1)
                {
                    printf("\nthe Dqueue is full\n");
                }
             else{
                printf("\nenter 1 for insert from end\n");
                printf("enter 2 for insert from front\n");
                scanf("%d",&m);
                printf("enter item \n");
                scanf("%d",&item);
                switch(m)
                {
                    case 1: insert_end(item);
                            break;
                    case 2: insert_front(item);
                            break;
                    default: printf("enter valid input\n");
                }
             }
                break;
        case 2:   int k;
                    if(front==-1)
                     {
                    printf("\nDqueue is empty\n");
                     }
            else {  printf("\n enter 1 for delete from front\n");
                    printf("enter 2 for delete from end\n");
                    scanf("%d",&k);
                    switch(k)
                    {
                        case 1: del_front();
                                break;
                        case 2: del_end();
                                break;
                        default : printf("please enter valid enput\n");
                    }
                
            }
                break;
        case 3: desp();
                break;
        case 4: exit(0);
                break;
        default: printf("\nenter valid input fron the menu\n");
    }
    }
}
