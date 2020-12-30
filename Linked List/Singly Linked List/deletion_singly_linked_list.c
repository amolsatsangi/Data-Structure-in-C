#include<stdio.h>
#include<stdlib.h>
int n;
struct node
{
    int data;
    struct node* next;
};
struct node * last;
struct node * CREATE_LIST(struct node *start)
{
    int data;
    struct node * node;
    char c;
    do
    {
        node=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter the number.\n");
        scanf("%d",&data);
        if(node==NULL)
        {
            printf("Overflow Error!");
        }
        else
        {
            node->data=data;
            node->next=NULL;
            if(start==NULL)
            {
                start=node;
                last=start;
            }
            else
            {
                last->next=node;
                last=node;
            }
            n++;
        }
        printf("Wanna add more nodes?\n");
        c=getch();
    }while(c=='y'|c=='Y');
return start;
}
struct node* DELETION_BEG(struct node* start)
{
    struct node * q;
    if(start==NULL)
    {
        printf("Empty linked list.\n");
    }
    else
    {
        q=start;
        start=q->next;
        free(q);
        n--;
    }
    return start;
}
struct node* DELETION_MID(struct node* start)
{
    struct node * q,* p;
    int mid=0,i=0;
    if(start==NULL)
    {
        printf("Empty linked list.\n");
    }
    else
    {
        q=start;
        mid=(n%2==0)?n/2:(n+1)/2;
        for(i=1;i<mid;i++)
        {
            p=q;
            q=q->next;
        }
        if(q==start)
        {
            start=start->next;
        }
        else
        {
            p->next=q->next;
        }
        free(q);
        n--;
    }
    return start;
}
struct node * DELETION_LAST(struct node * start)
{
    struct node * q,*p;
    if(start==NULL)
    {
        printf("The list is empty.\n");
    }

    else
    {
        q=start;
        while(q->next!=NULL)
        {
            p=q;
            q=q->next;
        }
        p->next=NULL;
        free(q);
        n--;
    }
    return start;
}
void DISPLAY(struct node * start)
{
    int i=0;
    struct node*q;
    q=start;
    if(start==NULL)
    {
        printf("Linked List is empty.\n");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(q->next!=NULL)
            {
                printf("%d -> ",q->data);
            }
            else
            {
                printf("%d\n",q->data);
            }
            q=q->next;
        }
    }
}
int main()
{
    int inp;
    struct node * start=NULL;
    printf("******DELETION FROM BEGINNING, MIDDLE and END in Singly Linked list*******\n");
    printf("\n");
    printf("\n");
    printf("\n");
    while(1)
    {
        printf("Enter your choice:\n");
        printf("1.Adding nodes in linked list.\n");
        printf("2.Deletion of first node.\n");
        printf("3.Deletion of middle node.\n");
        printf("4.Deletion of last node.\n");
        printf("5.Display the linked list.\n");
        printf("6.Exit.\n");
        scanf("%d",&inp);
        switch(inp)
        {
            case 1:start= CREATE_LIST(start);
                   break;
            case 2:start=DELETION_BEG(start);
                    break;
            case 3:start=DELETION_MID(start);
                    break;
            case 4:start=DELETION_LAST(start);
                    break;
             case 5:DISPLAY(start);
                    break;
            case 6:exit(0);
                   break;
            default:printf("WRONG CHOICE!!!!");
        }
    }
    return 0;
}
