#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *head = NULL, *temp, *newnode, *nextnode, *prevnode;

void create()
{
    int choice, j = 0;
    printf("Enter the count of data");
    scanf("%d", &choice);
    while ( j!=choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        newnode->prev = NULL;
        printf("Enter the data");
        scanf("%d", &newnode->data);
        if (head == NULL)
        {
            head =temp= newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        j++;
    }
}
void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
void insertionatbeg(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data");
    scanf("%d",&newnode->data);
    newnode->next=head;
    newnode->prev=NULL;
    head=newnode;
    display();
}
void insertionatend(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the value");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=newnode;
    newnode->prev=temp;
    display();
}
void insertionbtw(){
    int pos, i=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the position to insert the new data");
    scanf("%d",&pos);
    printf("enter the data");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    temp=head;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=newnode;
    nextnode->prev=newnode;
    newnode->prev=temp;
    newnode->next=nextnode;
    display();

}
void deletionbeg(){
    temp=head;
    nextnode=temp->next;
    nextnode->prev=NULL;
    free(temp);
    head=nextnode;
    display();
}
void deletionend(){
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    prevnode=temp->prev;
    prevnode->next=NULL;
    free(temp);
    display();

}
void deletionbtw(){
    int pos, i=1;
    temp=head;
    printf("enter the position at which the data is to be deleted");
    scanf("%d",&pos);
    while(i<=pos-1){
        temp=temp->next;
        i++;
    }
    prevnode=temp->prev;
    nextnode=temp->next;
    prevnode->next=temp->next;
    nextnode->prev=temp->prev;
    free(temp);
    display();
}
void main()
{
    while(1){
    int n;
    printf("Enter the choice\n1.creation\n2.display\n3.insertion at beginning\n4.insertion at end\n5.insertion in btw\n6.deletion at beginning\n7.deletion at end\n8.deletion in btw");
    scanf("%d", &n);
    
    switch (n)
    {
    case 1:
        create();
        break;
    case 2:
        display();
        break;  
    case 3:
        insertionatbeg();
        break; 
    case 4:
        insertionatend();
        break; 
    case 5:
        insertionbtw();
        break; 
    case 6:
        deletionbeg();
        break; 
    case 7:
        deletionend();
        break; 
    case 8:
        deletionbtw();
        break; 
    default:
        printf("wrong option");
        break;                               
    }
    }
}