#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*temp,*tail=NULL,*head=NULL,*newnode,*nextnode;

void creation(){

    newnode=(struct node*)malloc(sizeof(struct node));
}

void insertion(){
    creation();
    printf("Enter the data");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if (head==NULL){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
        tail->next=head;
    }
}

void Deletion(){
    int i=1, pos;
    printf("Enter the position you want to delete");
    scanf("%d",&pos);

    
    if(pos==1){
        temp=head;
        tail->next=temp->next;
        head=temp->next;
        free(temp);

    }

    else{
        temp=head;
        while(i<pos-1){
            temp=temp->next;
            i++;
           
        }
        
        nextnode=temp->next;
        if(tail==nextnode){
            tail=temp;

        }
        
        temp->next=nextnode->next;
        free(nextnode);
        
    }
}

void display(){
    temp=head;
    while(temp->next!=tail->next){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);

}

void main(){
    int choice;
    while(1){
        printf("1.Insertion\n2.Deletion\n3.display");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insertion();
                break;
            case 2:
                Deletion();
                break;
            case 3:
                display();
                break;    
            default:
                printf("Wrong choice\n");
                break;
        }
    }
    
}

