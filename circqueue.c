#include<stdio.h>
#define max 5
int queue[max];
int front=-1,rear=-1,a,i,n;

void isfull(){
    printf("Queue is full\n");
}
void isempty(){
    printf("Queue is empty\n");
}
void enqueue(){
    if((rear+1)%max==front){
        isfull();
    }
    else if(front==-1 && rear==-1){
        front++;
        rear++;
        printf("Enter the element to be inserted: \n");
        scanf("%d", &a);
        queue[rear] = a;
        printf("Inserted element is %d\n", queue[rear]);
    }
    else{
        rear=(rear+1)%max;
        printf("Enter the element to be inserted: \n");
        scanf("%d",&a);
        queue[rear]=a;
        printf("Inserted element is %d\n",queue[rear]);
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        isempty();
    }
    else if(front==rear){
        a=queue[front];
        printf("Deleted element is %d",a);
        front=-1;
        rear=-1;
    }
    else{
        a=queue[front];
        printf("Deleetd element is %d",a);
        front=(front+1)%max;
    }
}
void display(){
    if(front==-1 && rear==-1){
        isempty();
    }
    else{
        printf("elements in the queue are: \n");
        i=front;
        while(i!=rear){
            printf("%d\t",queue[i]);
            i=(i+1)%max;
        }
        printf("%d",queue[rear]);

    }
}
void peek(){
    if(front==-1 && rear==-1){
        isempty();
    }
    else{
        printf("Peek element is %d\n",queue[front]);
    }
}
void main()
{
    while (1)
    {
        printf("\nChoose an option:\n1.Display\n2.Enqueue\n3.Dequeue\n4.Peek\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            display();
            break;
        case 2:
            enqueue();
            break;
        case 3:
            dequeue();
            break;
        case 4:
            peek();
            break;
        default:
            printf("wrong option\n");
        }
    }
}