#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int v;

void adjmatrix(int matrix[MAX][MAX])
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("\nmatrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void topsort(int matrix[MAX][MAX], int vertices[v])
{
    int visited[v], count = 0;
    while (count != v)
    {
       
        for (int i = 0; i < v; i++)
        {
            int flag=1;
            for (int j = 0; j < v; j++)
            {
                if(visited[j]==vertices[i]){
                    flag=0;
                    break;
                }
            }
            for(int j=0;j<v;j++){
                 if (matrix[j][i] == 1)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                visited[i] = vertices[i];
                count++;
                for(int j=0;j<v;j++){
                    if(matrix[i][j]==1){
                        matrix[i][j]=0;
                    }
                }
            }
            
        }
    }
    printf("The visited list is :");
    for( int i=0 ; i<v ; i++){
        printf("%d ",visited[i]);
    }
}

    void main()
    {
        int matrix[MAX][MAX] = {0};
        printf("Enter the number of vertices: ");
        scanf("%d", &v);
        int vertices[v];
        for (int i = 0; i < v; i++)
        {
            printf("\nEnter vertices %d: ", i + 1);
            scanf("%d", &vertices[i]);
        }
        adjmatrix(matrix);
        topsort(matrix, vertices);
    }