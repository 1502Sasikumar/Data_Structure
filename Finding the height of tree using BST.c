//Finding the height of tree using BST
#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* Createnode(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *Insert(struct node* root,int data){
    if(root == NULL){
        return Createnode(data);
    }
    if(data < root->data){
        root->left = Insert(root->left,data);
    }
    else
    {
        root->right = Insert(root->right,data);
    }
    return root;
}

void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int height(struct node *root){
    if(root == NULL)
        return -1;
    else
    {
        int heightleft=height(root->left);
        int heightright=height(root->right);
        return (heightleft > heightright ? heightleft : heightright)+1;
    }
}


int main()
{
    struct node *root=NULL;
    int n;
    scanf("%d",&n);
    while(n--){
        int data;
        scanf("%d",&data);
        root=Insert(root,data);
    }
    inorder(root);
    printf("%d ",height(root));
}
