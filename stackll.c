
#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int stack[MAX];
int top=-1;

struct node
{
    int data;
    struct node *next;
} *head = NULL, *newnode, *temp , *prevnode , *nextnode;

void display()
{
    for(int i=0;i<=top;i++){
        printf("%d\n",stack[i]);
    }
}

    

void push(){
    if(top==MAX-1){
        printf("stack is full");
    }
    else{
        top++;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value");
        scanf("%d", &newnode->data);
        stack[top]=newnode->data;
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
        
        
    }

}


void pop(){
    if(top==-1){
        printf("stack is empty");
    }
    else{
    temp=head;
    
    
    prevnode=temp;
    temp=temp->next;
    top--;
    
    prevnode->next=NULL;
    free(temp);
    display();
    }
}
void search(){
    int val,count=0;
    printf("enter the value that should be found");
    scanf("%d",&val);
    for(int i=0;i<=top;i++){
        if(val==stack[i]){
           
            count=1;
        }
       
    }
    if(count==0){
        printf("element not found");
    }
    else{
        printf("element found");
    }
    
}

void main()
{
    int n;
    while (1)
    {
        printf("\n1.display\n2.push\n3.pop\n4.search");
        scanf("%d", &n);
        switch (n)
        {
           
        case 1:
            display();
            break;
        case 2:
            push();
            break;
        case 3:
            pop();
            break;
        case 4:
            search();
            break;
        default:
            printf("wrong choice");
            break;
        }
    }
}
