#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*head=NULL,*temp=NULL,*prev=NULL,*new,*prev,*nextn,*curr,*tev;
void insert(int d,int p)
{
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("The Memory is not Allocated Properly...");
    }
    else
    {
        temp=head;
        new->data=d;
        if(head==NULL)
        {
            new->next=NULL;
            head=new;
        }
        else if(p==1)
        {
            new->next=head;
            head=new;
        }
        else
        {
            for(int i=1;temp!=NULL && i<p-1;i++)
            {
                temp=temp->next;
            }
            if(temp->next==NULL)
            {
                temp->next=new;
                new->next=NULL;
            }
            else if(temp==NULL)
            {
                printf("Position out of range...\n");
            }
            else
            {
                new->next=temp->next;
                temp->next=new;
            }
        }
    }
}
void delete(int p)
{
    
    if(head==NULL)
    {
        printf("The list is empty...\n");
    }
    else
    {
        if(p==1)
        {
            head=head->next;
        }
        else
        {
            temp=head;
            for(int i=1;temp!=NULL && i<p-1;i++)
            {
                temp=temp->next;
            }
            struct node *prev;
            prev=temp;
            temp=temp->next;
            if(temp->next==NULL)
            {
                prev->next=temp->next;
            }
            else
            {
                prev->next=temp->next;                
            }
        }
    }
}
void display()
{
    temp=head;
    if(head==NULL)
    {
        printf("The List is Empty...\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }printf("NULL\n");
    }
}
void search(int el)
{
    int c=0;
    temp=head;
    if(head==NULL)
    {
        printf("The List is Empty...\n");
    }
    else
    {
        while(temp!=NULL)
        {
            if(el==temp->data)
            {
                printf("%d is found \n",temp->data);
                c=4;
                break;
            }
            temp=temp->next;
        }
        if(c!=4)
        {
            printf("%d not found...\n",el);
        }
    }
}
void reverse()
{
    prev=NULL;
    nextn=curr=tev=head;
    while(nextn!=NULL)
    {
        nextn=nextn->next;
        curr->next=prev;
        prev=curr;
        curr=nextn;
    }
    tev=prev;
    while(tev!=NULL)
    {
        printf("%d\t",tev->data);
        tev=tev->next;
    }printf("NULL\n");
}
void main()
{
    int pos,data,ch,elem,e=0;
    while(e!=4)
    {
        printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n5.SEARCH\n6.Reverse\n");
        printf("Choice - ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the Data:");
                scanf("%d",&data);
                printf("Enter the Position:");
                scanf("%d",&pos);
                insert(data,pos);
                break;
            case 2:
                printf("Enter the Position:");
                scanf("%d",&pos);
                delete(pos);
                break;
            case 3:
                printf("DISPLAYING...\n");
                display();
                break;
            case 4:
                printf("EXITS...\n");
                e=4;
                break;
            case 5:
                printf("Searching...\n");
                printf("Enter the Element:");
                scanf("%d",&elem);
                search(elem);
                break;
            case 6:
                printf("Reversing...\n");
                reverse();
                break;
            default:
                printf("INVALID CHOICE...\n");
        }
    }
}
