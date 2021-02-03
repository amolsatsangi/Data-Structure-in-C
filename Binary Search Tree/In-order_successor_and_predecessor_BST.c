//program to find inorder successor and predecessor of key in a binary search tree.
#include<stdio.h>
#include<stdlib.h>
struct node{
struct node* left;
struct node* right;
int key;
};
struct node * CREATE_BST(struct node* root)
{
    struct node * node,* p,*q;
    int key;
    char choice;
    do{
        node=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter the key.\n");
        scanf("%d",&key);
        if(node==NULL)
        {
            printf("Insufficient memory.\n");
            return root;
        }
        node->key=key;
        node->left=NULL;
        node->right=NULL;
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
        printf("Do you wanna add more nodes.\n");
        choice=getch();
    }while(choice=='y'||choice=='Y');
return root;
}
void INORDER_TRAVERSAL(struct node * root)
{
    if(root==NULL)
    {}
    else
    {
         INORDER_TRAVERSAL(root->left);
        printf("%d ->",root->key);
        INORDER_TRAVERSAL(root->right);
    }
}
 int INORDER_SUCCESSOR(int key,struct node* root)
 {
     struct node * p;
     int succ=-1;
     if(root==NULL)
     {
         return -1;
     }
     else
     {
         p=root;
         while(p!=NULL)
         {
             if(p->key==key)
             {
                 p=p->right;
                 while(p!=NULL&&p->left!=NULL)
                 {
                     p=p->left;
                 }
                    succ=(p!=NULL)?p->key:-1;
                 break;
             }
             else if(key<p->key)
             {
                 succ=p->key;
                 p=p->left;
             }
             else if(key>p->key)
             {
                 succ=p->key;
                 p=p->right;
             }
             if(p==NULL)
             {
                 succ=-1;
             }
         }
     }
     return succ;
 }
 int INORDER_PREDECESSOR(int key,struct node *root)
 {
     struct node * p;
     int pre=-1;
     if(root==NULL)
     {
         return -1;
     }
     else
     {
         p=root;
         while(p!=NULL)
         {
             if(p->key==key)
             {
                 p=p->left;
                 while(p!=NULL&&p->right!=NULL)
                 {
                     p=p->right;
                 }
                    pre=(p!=NULL)?p->key:-1;
                 break;
             }
             else if(key<p->key)
             {
                 pre=p->key;
                 p=p->left;
             }
             else
             {
                 pre=p->key;
                 p=p->right;
             }
             if(p==NULL)
             {
                 pre=-1;
             }
         }
     }
     return pre;
 }
int main()
{
    struct node * root=NULL;
    int key,suc,pre;
    printf("***In-order successor and predecessor.***\n");
    printf("Create BST.\n");
    root=CREATE_BST(root);
    printf("In-order traversal of BST.\n");
    INORDER_TRAVERSAL(root);
    printf("\nEnter the key of which the in-order successor and predecessor has to determine:\n");
    scanf("%d",&key);
    pre=INORDER_PREDECESSOR(key,root);
    printf("The in-order predecessor is %d.\n",pre);
    suc=INORDER_SUCCESSOR(key,root);
    printf("The in-order successor is %d.\n",suc);
    return 0;
}
