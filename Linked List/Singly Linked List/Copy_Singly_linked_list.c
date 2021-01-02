//copy a singly linked list into another one
#include<stdio.h>
#include<stdlib.h>
 struct node
 {
     int data;
     struct node * next;
 };
struct node * CREATE_LINKED_LIST(struct node * q)
{
    struct node * node,*last;
    char rep;
    int data;
    do
    {
        printf("\nEnter item:\n");
        scanf("%d",&data);
        node=(struct node*)(malloc(sizeof(struct node)));
        if(node==NULL)
        {
            printf("Overflow error\n");
        }
        else
        {
            node->data=data;
            node->next=NULL;
            if(q==NULL)
            {
                q=node;
                last=node;
            }
            else
            {
                last->next=node;
                last=node;
            }
        }
        printf("Wanna enter more items:\n");
        rep=getche();
    }while(rep=='y'||rep=='Y');
    return q;
}

struct node * COPY(struct node * q,struct node * p)
{
    struct node * node,*Q,*last;
    Q=q;
    while(Q!=NULL)
    {
        node=(struct node *)(malloc(sizeof(struct node)));
        if(node==NULL)
        {
            printf("Overflow error.\n");
        }
        else
        {
            node->data=Q->data;
            node->next=NULL;
            if(p==NULL)
            {
                p=node;
            }
            else
            {
                last->next=node;
            }
            last=node;
        }
        Q=Q->next;
    }
    return p;
}

void DISPLAY(struct node * q)
{
    struct node * s=q;
    if(s==NULL)
    {
        printf("Linked list is Empty:\n");
    }
    else
    {
        while(s!=NULL)
        {
            if(s->next!=NULL)
            {
                printf("%d - >",s->data);
            }
            else
            {
                printf("%d\n",s->data);
            }
            s=s->next;
        }
    }
}
 int main()
 {
     struct node * q=NULL,*p=NULL;
     printf("******Copy linked list to anther one.******\n");
     printf("Create linked list.\n");
     q=CREATE_LINKED_LIST(q);
     printf("\nThe original linked list is :\n");
     DISPLAY(q);
     p=COPY(q,p);
     printf("The second linked is :\n");
     DISPLAY(p);
     return 0;
 }
