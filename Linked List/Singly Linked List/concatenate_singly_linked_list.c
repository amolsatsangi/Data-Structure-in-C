//concatenation of two singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node * CREATE(struct node * start)
{
    int data;
    char c;
    struct node *last,*node;
    do{
    node=(struct node*)(malloc(sizeof(struct node)));
    if(node==NULL)
    {
        printf("Overflow error.\n");
    }
    else
    {
        printf("Enter item:\n");
        scanf("%d",&data);
        node->data=data;
        node->next=NULL;
        if(start==NULL)
        {
            start=node;
        }
        else
        {
            last->next=node;
        }
        last=node;
    }
    printf("Wanna add more nodes?\n");
    c=getche();
    printf("\n");
    }while(c=='y'||c=='Y');
return start;
}
struct node * CONCATENATE(struct node *s1,struct node *s2)
{
    struct node* q=s1;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=s2;
    return s1;
}
void DISPLAY(struct node * start)
{
    struct node * p;
    p=start;
    if(start==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        while(p!=NULL)
        {
            if(p->next!=NULL)
            {
                printf("%d - >",p->data);
            }
            else
            {
                printf("%d\n",p->data);
            }
            p=p->next;
        }
    }
}

int main()
{
    struct node * s1=NULL,* s2=NULL;
    printf("******Concatenation of Linked Lists*******\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Creation of first linked list.\n");
    s1=CREATE(s1);
    printf("The first linked list is:\n");
    DISPLAY(s1);
    printf("\nCreation of second linked list.\n");
    s2=CREATE(s2);
    printf("\nThe second linked list is:\n");
    DISPLAY(s2);
    s1=CONCATENATE(s1,s2);
    printf("\nThe concatenated list is:\n");
    DISPLAY(s1);
    free(s1);
    free(s2);
    return 0;
}
