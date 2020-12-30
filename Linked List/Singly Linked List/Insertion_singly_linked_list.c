#include<stdio.h>
#include<stdlib.h>
int n;
struct node{
int data;
struct node * next;
};

struct node * INSERTION_BEG(struct node * start)
{
    struct node *q,*node;
    int data;
    node=(struct node*)(malloc(sizeof(struct node)));
    printf("Enter the number.\n");
    scanf("%d",&data);
    if(node==NULL)
    {
        printf("Overflow Error.\n");
    }
    else
    {
        node->data=data;
        node->next=start;
        start=node;
        n++;
    }
    return start;
}
struct node * INSERTION_END(struct node * start)
{
    int data;
    struct node* node, *q;
    printf("Enter the number.\n");
    scanf("%d",&data);
    node=(struct node*)(malloc(sizeof(struct node)));
    if(node==NULL)
    {
        printf("Overflow error.\n");
    }
    else
    {
        node->data=data;
        node->next=NULL;
        q=start;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=node;
        n++;
    }
return start;
}
struct node * INSERTION_MID(struct node* start)
{
    int data,count=0,i=0;
    struct node* node, *q;
    printf("Enter the number.\n");
    scanf("%d",&data);
    node=(struct node*)(malloc(sizeof(struct node)));
    if(node==NULL)
    {
        printf("Overflow error.\n");
    }
    else
    {
        node->data=data;
        node->next=NULL;
        if(start==NULL)
        {
            start=node;
        }
        else
        {
            q=start;
            count=(n%2==0)?(n/2):(n+1)/2;
            for(i=1;i<count-1;i++)
            {
                q=q->next;
            }
            node->next=q->next;
            q->next=node;
        }
        n++;
    }
    return start;
}
void DISPLAY(struct node *start)
{
    int i=0;
    struct node *q;
    q=start;
    if(start==NULL)
    {
        printf("Linked List is Empty.\n");
    }
    else
    {
        for(i=0;i<n;i++)
        {
        if(q->next!=NULL)
            {
                printf("%d -> ",q->data);
                q=q->next;
            }
        else
            {
                printf("%d\n",q->data);
            }
        }
    }
}

int main()
{
    struct node * start=NULL;
    int inp;
    printf("************Insertion In Singly Linked List***********\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    while(1)
    {
        printf("Enter your choice:\n");
        printf("1.Insertion at beginning.\n");
        printf("2.Insertion at middle.\n");
        printf("3.Insertion at end.\n");
        printf("4.Display linked list.\n");
        printf("5.Exit.\n");
        scanf("%d",&inp);
        switch(inp)
        {
            case 1: start=INSERTION_BEG(start);
                    break;
            case 2: start=INSERTION_MID(start);
                    break;
            case 3: start=INSERTION_END(start);
                    break;
            case 4: DISPLAY(start);
                    break;
            case 5: exit(0);
            default: printf("Wrong Choice.\n");
        }
    }
        return 0;
}
