#include<stdio.h>
#include<stdlib.h>

void prims(start){
    
}

void main(){
    int v , choice ;
    printf("Enter number of vertices: ");
    scanf("%d",&v);
    int vertices[v];
    for(int i=0;i<v;i++){
        printf("\nEnter vertex %d: ",i+1);
        scanf("%d",&vertices[i]);
        
    }
    int matrix[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            matrix[i][j]=0;
        }
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            int weight;
            if(matrix[i][j]==0){
                printf("\nIs %d and %d related? Type 1 for yes else 0 :",vertices[i],vertices[j]);
                scanf("%d",&choice);
                if(choice==1){
                    printf("\nType the weight between the edges");
                    scanf("%d",&weight);
                    matrix[i][j]=weight;
                    matrix[j][i]=weight;
                }
            
            }
        }
    }
    // for(int i=0;i<v;i++){
    //     for(int j=0;j<v;j++){
    //         printf("\nWeight between %d and %d is: %d ",vertices[i],vertices[j],matrix[i][j]);
    //     }
    
    // }
    int vertex , start ;
    printf("\nvertices are: ");
    for(int i=0;i<v;i++){
        printf("%d ",vertices[i]);
    }
    printf("\nchoose a vertex: ");
    scanf("%d",&vertex);
    for(int i=0 ; i<v ; i++){
        if(vertices[i]==vertex){
            start=i;
            break;
        }
    }
    prims(start);
    
}