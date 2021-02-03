//BST serching takes O(log n) time in ideal case when BST is perfectly balanced but in worst case it may take O(n) time.
#include<stdio.h>
#include<stdlib.h>
struct node {
int key;
struct node* left;
struct node* right;
};
struct node * CREATE_BST(struct node * root)
{
    int key;
    struct node * node,*p,*q;
    char choice;
    do{
        node=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter the key:\n");
        scanf("%d",&key);
        node->key=key;
        node->right=NULL;
        node->left=NULL;
        if(root==NULL)
        {
            root=node;
        }
        else
        {
            q=root;
            while(q!=NULL)
            {
                if(key<q->key)
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
            if(key<p->key)
            {
                p->left=node;
            }
            else
            {
                p->right=node;
            }
        }
        printf("Do you wanna add more nodes?\n");
        choice=getch();
    }while(choice=='y'||choice=='Y');
    return root;
}
void BST_SEARCH(struct node *root,int key)
{
    struct node * p=root;
    int flag=0;
    while(p!=NULL)
    {
        if(p->key==key)
        {
            flag=1;
            break;
        }
        else if(key<p->key)
        {
            p=p->left;
        }
        else
        {
            p=p->right;
        }
    }
    if(flag==1)
        printf("The key %d is found.\n",key);
    else
        printf("The key %d is not there in BST.\n",key);
}
void INORDER_TRAVERSAL(struct node *root)
{
    if(root==NULL){}
    else{
        INORDER_TRAVERSAL(root->left);
        printf("%d - > ",root->key);
        INORDER_TRAVERSAL(root->right);
    }
}
int main()
{
    int key;
    struct node * root=NULL;
    printf("***Searching in BST****\n");
    printf("BST creation.\n");
    root=CREATE_BST(root);
    printf("\nThe inorder traversal of BST:\n");
    INORDER_TRAVERSAL(root);
    printf("\nEnter the item which you want to search\n");
    scanf("%d",&key);
    BST_SEARCH(root,key);
    return 0;
}
