#include <stdio.h>
#include <stdlib.h>

#define max 5
int queue[max];
int front =-1, rear =-1;

struct node
{
    int data;
    struct node *next;
} *head = NULL, *newnode, *temp , *delete , *nextnode;

void display()
{
    if (front==rear==-1)
    {
        printf("Queue is empty");
    }
    else{
        temp=head;
        while (temp->next!=NULL){
            printf(" %d",temp->data);
            temp=temp->next;
        }
        printf(" %d",temp->data);
    }
    
}

void create()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
}

void enqueue()
{
    if(rear==max-1){
        printf("queue is full");
    }
    
    else if(rear==-1 && front==-1)
    {
        create();
        front++;
        rear++;
        temp=head=newnode;
        
        
    }
    else{
        create();
        rear++;
        temp->next=newnode;
        temp=temp->next;
        
        }

}

void dequeue(){
    if(front==rear==-1){
        printf("queue is empty");
    }
    else if(front==rear){
        free(temp);
        front=-1;
        rear=-1;
    }
    else{
        temp=head;
        delete=temp;
        temp=temp->next;
        free(delete);
        head=temp;
        front++;
    }
    
}
void peek(){
    if(front=-1 && rear==-1){
        printf("queue is empty\n");
    }
    else{
        printf("%d",temp->data);
    }
}


void main()
{
    int n;
    while (1)
    {
        printf("\n1.enqueue\n2.display\n3.dequeue\n4.peek\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            enqueue();
            break;
        case 2:
            display();
            break;
        case 3:
            dequeue();
            break;
        case 4:
            peek();
            break;
        default:
            printf("wrong choice");
            break;
        }
    }
}
