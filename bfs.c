#include<stdio.h>
#include<stdlib.h>

void main(){
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    
    int vertices[v];
    for(int i=0;i<v;i++){
        printf("\nEnter vertices %d: ",i+1);
        scanf("%d",&vertices[i]);
        // printf("%d",vertices[i]);
        
    }
    int matrix[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            matrix[i][j]=2;
        }
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            int rel;
            if(matrix[i][j]==1 || matrix[i][j]==0){
                continue;
            }
            else{
                printf("Is %d and %d related? Type 1 if yes,else 0: ",vertices[i],vertices[j]);
                scanf("%d",&rel);
                
                if(rel==1){
                    matrix[i][j]=1;
                    matrix[j][i]=1;
                }
                else{
                    matrix[i][j]=0;
                    matrix[j][i]=0;
                }

            }
        }
    }
    for(int i=0;i<v;i++){
    printf("\n%d is related to: ",vertices[i]);
    for(int j=0;j<v;j++){
        if(matrix[i][j]==1){
                printf("%d ",vertices[j]);
            }
        }
    }
    int visited[v], queue[v] , front=-1 , rear=-1 , num,k=0 ;
    for(int i=0 ; i<v; i++){
        visited[i]=0;
    }
    printf("\nSelect any of the vertices to start the traversal: ");
    scanf("%d",&num);
    front++;
    rear++;
    queue[rear]=num;
    while(k!=v){
        
        num=queue[front];
        int index;
        visited[k]=queue[front];
        if(front==rear){
           
            front=rear=-1;
        }
        else{
            front++;
        }
        if(front==-1 && rear==-1){
            
            front++;
        }
        for(int i=0;i<v;i++){
            if(num==vertices[i]){
                index=i;
                break;
            }
        }
       
        for(int i=0;i<v;i++){
            int flag=1;
            if(matrix[index][i]==1){
                for(int j=0;j<v;j++){
                    if(vertices[i]==visited[j]){
                        flag=0;
                        break;
                    }
                }
                if(flag==1){
                    for(int j=front;j<=rear;j++){
                        if(vertices[i]==queue[j]){
                            flag=0;
                            break;
                        }
                        
                    }
                }
                if(flag==1){
                    rear++;
                    queue[rear]=vertices[i];
                }
            }
        }
        k++;

    }
    printf("The visited list is :");
    for (int i=0 ; i<v ; i++){
        printf("%d ",visited[i]);
    }


}