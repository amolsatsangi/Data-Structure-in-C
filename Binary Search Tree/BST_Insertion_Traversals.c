//Program  for insertion, in-order ,pre-order and Post-order traversal in a binary  search tree
#include<stdio.h>
#include<stdlib.h>
struct node{
int key;
struct node *left;
struct node *right;
};
struct node * INSERTION(struct node* root)
{
    struct node *node,*q,*p;
    int data;
    printf("Enter the key value of node.\n");
    scanf("%d",&data);
    node=(struct node*)(malloc(sizeof(struct node)));
    node->key=data;
    node->left=NULL;
    node->right=NULL;
    if(root==NULL)
    {
        root=node;
        return root;
    }
    else
    {
        q=root;
        while(q!=NULL)
        {
            if(data<q->key)
            {
                p=q;
                q=q->left;
            }
            else
            {
                p=q;
                q=q->right;
            }
        }
        if(data<=p->key)
        {
            p->left=node;
        }
        else
        {
            p->right=node;
        }
        return root;
    }
}
void INORDER(struct node * root)
{
    if(root==NULL)
    {}
    else
    {
        INORDER(root->left);
        printf("%d -> ",root->key);
        INORDER(root->right);
    }
}
void POSTORDER(struct node *root)
{
    if(root==NULL)
    {}
    else
    {
        POSTORDER(root->left);
        POSTORDER(root->right);
        printf("%d -> ",root->key);
    }
}

void PREORDER(struct node * root)
{
    if(root==NULL){}
    else
    {
        printf("%d -> ",root->key);
        POSTORDER(root->left);
        POSTORDER(root->right);
    }
}
void main()
{
    int choice;
    struct node *root=NULL;
    printf("****Binary Search Tree creation, In-order traversal.****\n");
    while(1)
    {
        printf("1.Insert a node\n");
        printf("2.In-order traversal\n");
        printf("3.Pre-order Traversal\n");
        printf("4.Post-order Traversal.\n");
        printf("5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:root=INSERTION(root);
                   break;
            case 2:if(root==NULL)
                    {
                        printf("The tree is empty.\n");
                    }
                    else
                    {
                        INORDER(root);
                        printf("\n");
                    }
                   break;
            case 3:if(root==NULL)
                    {
                        printf("The tree is empty.\n");
                    }
                    else
                    {
                        PREORDER(root);
                        printf("\n");
                    }
                    break;
            case 4:  if(root==NULL)
                    {
                        printf("The tree id empty.\n");
                    }
                    else
                    {
                        POSTORDER(root);
                        printf("\n");
                    }
            case 5:exit(0);
            default:printf("Wrong value");
        }
    }
}
