#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
} *root, *parent, *newnode, *temp,*delete;

void insertion()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d", &newnode->data);
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        temp = root;
        int should_continue = 1;
        while (should_continue == 1)
        {
            if (temp->data == newnode->data)
            {
                should_continue = 0;
                break;
            }
            while (newnode->data < temp->data)
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = newnode;
                    temp = newnode;
                }
            }
            while (newnode->data > temp->data)
            {
                printf("1\n");
                if (temp->right != NULL)
                {
                    temp = temp->right;
                }
                else
                {
                    temp->right = newnode;
                    temp = newnode;
                }
            }
            should_continue = 1;
        }
    }
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void predecessor(){
    temp=root;
    temp=temp->left;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

void successor(){
    temp=root;
    temp=temp->right;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

struct node* search( int value){
    int should_continue=1;
    temp=root;

    if(value==root->data){
        return temp;
    }
    while (should_continue==1){
        while(value<temp->data){
            temp=temp->left;
            if(temp->data==value){
                should_continue=0;
                break;
            }
        }
        while(value>temp->data){
            temp=temp->right;
            if(temp->data==value){
                should_continue=0;
                break;
            }
        }
    }
    return temp;    
}





void deletion(){
    int value;
    printf("Enter the value to be deleted");
    scanf("%d",&value);
    delete=search(value);
    if(delete->left==NULL && delete->right==NULL){
        free(delete);
    }
    else if(delete->left==NULL && delete->right!=NULL){
        delete=delete->right;
        free(delete->right);
    }
}


void main()
{
    int choice;
    while (1)
    {
        printf("\n1.insertion\n2.Inorder traversal\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            inorder(root);
            break;
        default:
            printf("wrong choice");
            break;
        }
    }
}
