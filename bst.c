#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
} *root, *parent, *newnode, *temp, *predec = NULL, *succ = NULL, *parent1;

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
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int search(int value)
{
    int should_continue = 1, flag = 0;
    temp = root;
    if (value == root->data)
    {
        flag = 1;
    }
    while (should_continue == 1 && flag == 0)
    {
        while (value < temp->data)
        {
            parent = temp;
            temp = temp->left;
            if (temp->data == value)
            {
                should_continue = 0;
                flag = 1;
                break;
            }
        }
        while (value > temp->data)
        {
            parent = temp;
            temp = temp->right;
            if (temp->data == value)
            {
                should_continue = 0;
                flag = 1;
                break;
            }
        }
    }
    return flag;
}
struct node *successor(int value)
{
    search(value);
    if (temp->right == NULL)
    {
        printf("No successor");
    }
    else
    {
        succ = temp;
        parent1 = succ;
        succ = succ->right;
        while (succ->left != NULL)
        {
            parent = succ;
            succ = succ->left;
        }
    }
}
struct node *predecessor(int value)
{
    search(value);
    if (temp->left == NULL)
    {
        printf("No predecessor");
    }
    else
    {
        predec = temp;
        predec = predec->left;
        while (predec->right != NULL)
        {
            predec = predec->right;
        }
    }
}

void deletion()
{
    int value;
    printf("Enter the value to be deleted");
    scanf("%d", &value);
    search(value);
    if (temp->left == NULL && temp->right == NULL)
    {
        if (parent->left == temp)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
    }
    if (temp->left != NULL && temp->right != NULL)
    {
        successor(temp->data);
        temp->data = succ->data;
        if (succ == parent1->left)
        {
            parent1->left = NULL;
        }
        else
        {
            parent1->right = NULL;
        }
    }
    else
    {
        if (temp == parent->left)
        {
            if (temp->right == NULL)
            {
                parent->left = temp->left;
            }
            else
            {
                parent->left = temp->right;
            }
        }
        else if (temp == parent->right)
        {
            if (temp->left == NULL)
            {
                parent->right = temp->right;
            }
            else
            {
                parent->right = temp->left;
            }
        }
    }
}

void main()
{
    int choice, value;
    while (1)
    {
        printf("\n1.insertion\n2.Inorder traversal\n3.Predecessor\n4.SUccessor\n5.Deletion\n6.Preorder traversal\n7.Postorder traversal\n8.Search\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("Enter value whose predecessor is to be found: ");
            scanf("%d", &value);
            predecessor(value);
            printf("\n%d", predec->data);
            break;

        case 4:
            printf("Enter value whose successor is to be found: ");
            scanf("%d", &value);
            successor(value);
            printf("\n%d", succ->data);
            break;
        case 5:
            deletion();
            break;
        case 6:
            preorder(root);
            break;
        case 7:
            postorder(root);
            break;
        case 8:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        default:
            printf("wrong choice");
            break;
        }
    }
}