#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    p=(node*)malloc(sizeof(node));
    p->data=x;

    printf("Enter left child of %d:\n",x);
    p->left=create();

    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}

void preorder(node *t)
{
    if(t!=NULL)
    {
        printf("%d\t",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf("%d\t",t->data);
        inorder(t->right);
    }
}
void postorder(node *t)
{
    if(t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d\t",t->data);
    }
}

void main()
{
    int ch;
    node *root;
	do
	{
        printf("\nMENU\n");
        printf("-------------------\n");
        printf("1.create tree\n");
        printf("2.inorder\n");
        printf("3.pre order\n");
        printf("4.postorder\n");
        printf("5.exit\n");
        printf("enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:root=create();
                break;
            case 2:inorder(root);
                break;
            case 3:preorder(root);
                break;
            case 4:postorder(root);
                break;
            case 5:exit(0);break;
        }
	}while(ch>=1 && ch<=5);
}
