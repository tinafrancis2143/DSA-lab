#include <stdio.h>
#define max 5
int queue[max];
int front = -1, rear = -1, a, n;
void isfull()
{
    printf("Queue is full\n");
}
void isempty()
{
    printf("Queue is empty\n");
}
void enqueue()
{
    if (rear == max - 1)
    {
        isfull();
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        printf("Enter the element to be inserted: \n");
        scanf("%d", &a);
        queue[rear] = a;
        printf("Inserted element is %d\n", queue[rear]);
    }
    else
    {
        rear++;
        printf("Enter the element to be inserted: \n");
        scanf("%d", &a);
        queue[rear] = a;
        printf("Inserted element is %d\n", queue[rear]);
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        isempty();
    }
    else if (front == rear)
    {
        a = queue[front];
        printf("Deleted element is %d\n", a);
        front = -1;
        rear = -1;
    }
    else
    {
        a = queue[front];
        printf("Deleted element is %d\n", a);
        front++;
    }
}
void peek()
{
    if (front == -1 && rear == -1)
    {
        isempty();
    }
    else
    {
        printf("peek element is %d", queue[front]);
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        isempty();
    }
    else
    {
        printf("The elements in the queue are: \n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
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