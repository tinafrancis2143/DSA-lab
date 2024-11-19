#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *head = NULL, *temp, *newnode;

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
    // case 3:
    //     display();
    //     break; 
    // case 4:
    //     display();
    //     break; 
    // case 5:
    //     display();
    //     break; 
    // case 6:
    //     display();
    //     break; 
    // case 7:
    //     display();
    //     break; 
    // case 8:
    //     display();
    //     break;                               
    }
    }
}