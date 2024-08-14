/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
    
}Node;
void insert_begin(Node **head)
{
    Node *ptr=(Node*)malloc(sizeof(Node));
    int item;
    if(ptr==NULL)
    {
        printf("No memory allocated\n");
    }
    else
    {
        printf("Enter the item for insert_begin : \n");
        scanf("%d",&item);
        if((*head)==NULL)
        {
            ptr->data=item;
            ptr->prev=NULL;
            ptr->next=NULL;
            (*head)=ptr;
        }
        else
        {
            ptr->data=item;
            ptr->prev=NULL;
            ptr->next=(*head);
            (*head)=ptr;
            
        }
    }
}
void insert_random(Node **head)
{
    Node *ptr=(Node*)malloc(sizeof(Node));
    Node *temp=(*head);
    if(ptr==NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        int item;
        printf("Enter the item u want insert_random\n");
        scanf("%d",&item);
        ptr->data=item;
        if(temp==NULL)
        {
            ptr->next=(*head);
            ptr->prev=NULL;
            (*head)=ptr;
        }
        else
        {
            int pos;
            printf("Enter the position u want insert\n");
            scanf("%d",&pos);
            if(pos==0)
            {
                ptr->next=(*head);
                ptr->prev=NULL;
                (*head)=ptr;
            }
            else
            {
                Node *first=NULL;
                int index;
                for(index=0;index<pos;index++)
                {
                    first=temp;
                    temp=temp->next;
                    if(temp==NULL)
                    {
                        printf("There are %d less than elements\n",pos);
                    }
                }
                first->next=ptr;
                ptr->prev=first->next;
                ptr->next=temp;
            }
        }
        
        
    }
    return;
}
void Display(Node *head)
{
    Node * temp;
    temp=head;
    if(head==NULL)
    {
        printf("lIST IS EMPTY\n");
    }
    else
    {
        printf("%d",temp->data);
        temp=temp->next;
        while(temp!=NULL)
        {
            printf("->%d",temp->data);
            temp=temp->next;
            
        }
    }
    
}
void insert_last(Node **head)
{
    Node *ptr=(Node*)malloc(sizeof(Node));
    Node *temp;
    temp=(*head);
    if(ptr==NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        int item;
        printf("Enter the data you want insert\n");
        scanf("%d",&item);
        ptr->data=item;
        if((*head)==NULL)
        {
            ptr->next=(*head);
            ptr->prev=NULL;
            (*head)=ptr;
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->prev=temp;
            ptr->next=NULL;
        }
        
    }
}
void delete_begin(Node **head)
{
    Node *ptr;
    if((*head)==NULL)
    {
        printf("Deletion is not possible when node is EMPTY\n");
    }
    else
    {
        ptr=(*head);
        (*head)=ptr->next;
        (*head)->prev=NULL;
        free(ptr);
    }
}
void delete_random(Node **head)
{
    Node *ptr=(*head);
    Node *first;
    if((*head)==NULL)
    {
        printf("Deletion is not possible list is EMPTY\n");
    }
    int index;
    int pos;
    printf("Enter the position u want to delete\n");
    scanf("%d",&pos);
    if(pos==0)
    {
        ptr=(*head);
        (*head)=ptr->next;
        (*head)->prev=NULL;
        free(ptr);
    }
    else
    {
        for(index=0;index<pos;index++)
        {
            first=ptr;
            ptr=ptr->next;
            if(ptr->next==NULL)
            {
                break;
            }
        }
        printf("\nDeletion data %d\n",ptr->data);
        first->next=ptr->next;
        ptr->next->prev=first;
        free(ptr);
        printf("Deletion at posible index value of : %d\n",index);
    }
    
}
void delete_last(Node **head)
{
    Node *ptr;
    ptr=(*head);
    Node *temp;
    if((*head)==NULL)
    {
        printf("Deletion is not possible when node is EMPTY\n");
    }
    else if(ptr->next==NULL)
    {
        ptr=NULL;
        free(ptr);
    }
    else
    {
        ptr=(*head);
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        ptr->prev=temp;
        free(ptr);
        
    }
    
}
int main()
{
    Node *head=NULL;
    int choice=0;
    do
    {
        printf("\nChoose option from below list\n");
        printf("1.Insert at begin\n2.Insert at random\n3.Insert at last\n4.Delete at begin\n5.Delete at random\n6.Delete at last\n7.Display\n");
        printf("Enter the choice you want to do\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert_begin(&head);
                break;
            case 2:
                insert_random(&head);
                break;
            case 3:
                insert_last(&head);
                break;
            case 4:
                delete_begin(&head);
                break;
            case 5:
                delete_random(&head);
                break;
            case 6:
                delete_last(&head);
                break;
            case 7:
                Display(head);
                break;
            default:
                printf("Next time give corct value\n");
                break;
        }
    }while(choice!=0);
}

