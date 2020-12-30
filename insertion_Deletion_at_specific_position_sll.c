//Insertion and deletion at specific position in singly linked list 
#include<stdio.h>
#include<stdlib.h>
int n;
struct node
{
    int data;
    struct node* next;
};
struct node * INSERTION(struct node *start,int item,int pos)
{
    struct node* node,*q,*p;
    int i=0;
    node=(struct node*)(malloc(sizeof(struct node)));
    if(node==NULL)
    {
        printf("Overflow Error!!");
        return start;
    }
    if(start==NULL&&pos!=1)
    {
        printf("Since the list is empty so the position must be 1.\n");
        return start;
    }
    if(start!=NULL&&(pos<1||pos>n+1))
    {
        printf("Wrong Position!!\n");
        return start;
    }
        node->data=item;
        node->next=NULL;
        if(pos==1)
        {
            node->next=start;
            start=node;
        }
        else
        {
            q=start;
            for(i=1;i<pos-1;i++)
            {
                q=q->next;
            }
            node->next=q->next;
            q->next=node;
            }
            n++;
return start;
}

struct node * DELETION(struct node * start,int pos)
{
    int i;
    struct node * q,*p;
    if(start==NULL)
    {
        printf("List is empty.\n");
    }
    if(pos<1||pos>n)
    {
        printf("Wrong Position!!\n");
    }
    else
    {
        if(pos==1)
        {
            q=start;
            start=start->next;
            free(q);
        }
        else
        {
            q=start;
            for(i=1;i<pos;i++)
            {
                p=q;
                q=q->next;
            }
            p->next=q->next;
            free(q);
        }
        n--;
    }
return start;
}
void DISPLAY(struct node * start)
{
    int i=0;
    struct node * q;
    q=start;
    if(start==NULL)
    {
        printf("The list is empty!\n");
    }
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
int main()
{
    int inp,item,pos;
    struct node * start=NULL;
    printf("****DELETION AND INSERTION AT SPECIFIC POSITION IN SINGLY LINKED LIST****\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    while(1)
    {
        printf("Enter your choice.\n");
        printf("1.Insertion at specific position.\n");
        printf("2.Deletion at specific position.\n");
        printf("3.Display the linked list.\n");
        printf("4.exit.\n");
        scanf("%d",&inp);
        switch(inp)
        {
            case 1:printf("Enter the item and position where it has to be inserted.\n");
                    scanf("%d %d",&item,&pos);
                    start=INSERTION(start,item,pos);
                    break;
            case 2:printf("Enter the position from where the item has to be deleted.\n");
                    scanf("%d",&pos);
                    start=DELETION(start,pos);
                    break;
            case 3: DISPLAY(start);
                    break;
            case 4: exit(0);
                    break;
            default:printf("WRONG CHOICE!!");
        }
    }
    return 0;
}
