//CREATION AND DISPLAY A SINGLY LINKED LIST
#include<stdlib.h>
#include<stdio.h>
struct node
{
int data;
struct node* next;
};
struct node* CREATE(struct node* start)
{
    struct node* node,* q;
    int data;
    printf("Enter the number to be added.\n");
    scanf("%d",&data);
    node=(struct node*)(malloc(sizeof(struct node)));
    node->data=data;
    node->next= NULL;
    if(node==NULL)
    {
        printf("The memory is not located\n");
    }
    else{
        if(start==NULL)
        {
            start=node;
        }
        else
        {
            q=start;
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=node;
        }
    }
    return start;
}
void DISPLAY(struct node* start)
{
    struct node * q;
    q=start;
    if(q==NULL)
    {
        printf("The list is empty.\n");
    }
    else{
        while(q!=NULL)
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
    struct node* start= NULL;
    printf("*******Create and display Linked list*******\n");
    while(1)
    {
        int inp;
        printf("Please enter your choice:\n");
        printf("1. Add item to linked list\n");
        printf("2. Display linked list\n");
        printf("3. Exit\n");
        scanf("%d",&inp);
        switch(inp)
        {
            case 1: start=CREATE(start);
                    break;
            case 2: DISPLAY(start);
                    break;
            case 3: exit(0);
            default:printf("Wrong choice");
        }
    }
    return 0;
}
