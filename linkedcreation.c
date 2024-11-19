#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *newnode, *temp , *prevnode , *nextnode;

void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
void insertionbeg()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter number to be inserted at beginning: ");
    scanf("%d", &newnode->data);
    newnode->next=head;
    head=newnode;

    
}
void creation()
{
    int choice, i;
    printf("Enter no of nodes to be created");
    scanf("%d", &choice);
    int j = 0;
    while (j != choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        j++;
    }
}

void insertionend(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the value to be inserted");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;


}
void insertionbtw(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the value to be inserted");
    scanf("%d",&newnode->data);
    printf("enter the position where the new data is to be inserted");
    int pos,i=1;
    scanf("%d",&pos);
    temp=head;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    display();
}
void deletefrnt(){
    temp=head;
    head=temp->next;

    free(temp);
    display();
}
void deleteend(){
    temp=head;
    while(temp->next!=0)
    {
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=NULL;
    free(temp);
    display();
}
void  deletebtw(){
    int pos , i=1 ;
    temp=head;
    nextnode=head;
    printf("Enter the position");
    scanf("%d",&pos);
    while(i<=pos-1){
        temp=nextnode;
        nextnode=nextnode->next;
        i++;
    }
    temp->next=nextnode->next;
    free(nextnode);
    display();
}
void main()
{
    int n;
    while (1)
    {
        printf("\n1.creation\n2.display\n3.insertion at beginning\n4.insertion at end\n5.insertion in between\n6.deletion from front\n7.deletion from end\n8.deletion in btw");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            creation();
            break;
        case 2:
            display();
            break;
        case 3:
            insertionbeg();
            break;
        case 4:
            insertionend();
            break;
        case 5:
            insertionbtw();
            break;
        case 6:
            deletefrnt();
            break;
        case 7:
            deleteend();
            break; 
        case 8:
            deletebtw();
            break;    
        default:
            printf("wrong choice");
            break;
        }
    }
}
