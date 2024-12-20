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

    // for(int i=0;i<v;i++){
    //     for(int j=0;j<v;j++){
    //         printf("%d ",matrix[i][j]);
    //     }
    //     printf("\n");
    // }

//using another method to print

for(int i=0;i<v;i++){
    printf("%d is related to: ",vertices[i]);
    for(int j=0;j<v;j++){
        if(matrix[i][j]==1){
            printf("%d",vertices[j]);
        }
    }
}








}