#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
};
void insertatbegin(struct node **head,int val)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Data not allocated");
        return;
    }
    temp->data=val;
    if(!(*head))
    {
        temp->next=temp;
        temp->prev=temp;
        *head=temp;
        return;
    }
    struct node *itr=*head;
    while(itr->next!=*head)
    {
        itr=itr->next;
    }
    temp->next=itr->next;
    temp->prev=itr;
    itr->next=temp;
    (*head)->prev=temp;
    *head=temp;
    return;

}
void insertatend(struct node **head,int val)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Data not allocated");
        return;
    }
    temp->data=val;
    if(!(*head))
    {
        temp->next=temp;
        temp->prev=temp;
        *head=temp;
        return;
    }
    struct node *itr=*head;
    while(itr->next!=*head)
    {
        itr=itr->next;
    }
    temp->next=itr->next;
    temp->prev=itr;
    itr->next=temp;
    (*head)->prev=temp;
    return;
}
void insertafterk(struct node **head,int val,int k)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Data not allocated");
        return;
    }
    temp->data=val;
    if(!(*head))
    {
        temp->next=temp;
        temp->prev=temp;
        *head=temp;
        return;
    }
    struct node *itr=*head;
    do
    {
        if(itr->data==k)
        {
            temp->next=itr->next;
            temp->prev=itr;
            itr->next=temp;   
            temp->next->prev=temp;
            return;
        }
        itr=itr->next;
    } while (itr!=*head);
    printf("node not found");  
}
void insertbeforek(struct node **head,int val,int k)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Data not allocated");
        return;
    }
    temp->data=val;
    if(!(*head))
    {
        temp->next=temp;
        temp->prev=temp;
        *head=temp;
        return;
    }
    struct node *itr=*head;
    if((*head)->data==k)
    {
        while(itr->next!=*head)
        {
            itr=itr->next;
        }
        temp->next=itr->next;
        temp->prev=itr;
        itr->next=temp;
        (*head)->prev=temp;
        *head=temp;
        return; 
    }
    while(itr->next!=*head && itr->next->data!=k)
    {
        itr=itr->next;
    }
    if(itr->next==*head)
    {
        printf("node not found");
        return;
    }
    temp->next=itr->next;
    temp->prev=itr;
    itr->next=temp;   
    temp->next->prev=temp;
    return;
}
void deleteatbegin(struct node **head)
{
    if(!(*head))
    {
        return;
    }
    struct node *temp=*head,*itr=*head;
    while(itr->next!=*head)
    {
        itr=itr->next;
    }
    if(*head==itr)
    {
        free(*head);
        *head=NULL;
        return;
    }
    itr->next=(*head)->next;
    *head=(*head)->next;
    (*head)->prev=itr;
    free(temp);
}
void deleteatend(struct node **head)
{
    if(!(*head))
    {
        return;
    }
    if((*head)->next==*head)
    {
        free(*head);
        *head=NULL;
        return;
    }
    struct node *temp=*head,*itr=*head;
    while(itr->next->next!=*head)
    {
        itr=itr->next;
    }
    temp=itr->next;
    itr->next=temp->next;
    (*head)->prev=itr;
    free(temp);
    return;
}
void deletek(struct node **head,int k)
{
    if(!(*head))
    {
        return;
    }
    struct node *temp=*head,*itr=*head;
    if((*head)->data==k)
    {
        if((*head)->next==*head)
        {
            free(*head);
            *head=NULL;
            return;
        }
        else
        {
            while(itr->next!=*head)
            {
                itr=itr->next;
            }
            *head=(*head)->next;
            itr->next=*head;
            (*head)->prev=itr;
            free(temp);
            return;
        }
    }
    while(itr->next!=*head && itr->next->data!=k)
    {
        itr=itr->next;
    }
    if(itr->next==*head)
    {
        printf("node not found");
        return;
    }
    temp=itr->next;
    itr->next=temp->next;
    temp->next->prev=itr;
    free(temp);
    return;
}
void display(struct node **head)
{
    if(!(*head))
    {
        printf("list is empty");
        return;
    }
    struct node *itr=*head;
    do
    {        
        printf("%d ",itr->data);
        itr=itr->next;
    } while (itr!=*head);
    return;
}
int main()
{
    struct node *head=NULL;
    int a,val,k;
    char c;
    do
    {
        printf("1. insert at beginning\n2. insert at end\n3. insert after k\n4. insert before k\n5. delete from beginning\n6. delete from end\n7. delete a node of value k\n8. display\nEnter your choice: ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            {
                printf("Enter the value to insert: ");
                scanf("%d",&val);
                insertatbegin(&head,val);
                break;
            }
            case 2:
            {
                printf("Enter the value to insert: ");
                scanf("%d",&val);
                insertatend(&head,val);
                break;
            }
            case 3:
            {
                printf("Enter the value to insert: ");
                scanf("%d",&val);
                printf("Enter the value after to insert: ");
                scanf("%d",&k);
                insertafterk(&head,val,k);
                break;
            }
            case 4:
            {
                printf("Enter the value to insert: ");
                scanf("%d",&val);
                printf("Enter the value before to insert: ");
                scanf("%d",&k);
                insertbeforek(&head,val,k);
                break;
            }
            case 5:
            {
                deleteatbegin(&head);
                break;
            }
            case 6:
            {
                deleteatend(&head);
                break;
            }
            case 7:
            {
                printf("Enter the value to delete: ");
                scanf("%d",&k);
                deletek(&head,k);
                break;
            }
            case 8:
            {
                display(&head);
                printf("\n");                
                break;
            }
            default:
            {
                printf("invalid choice!!\n");
            }
        }
        printf("Do you want to continue?(y/n)\n");
        scanf(" %c",&c);
    } while (c=='y');
    return 0;
}




