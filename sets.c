#include <stdio.h>

int U[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int a, b, c,d, flag = 0, count = 0;
void main()
{
    printf("Enter the size of first set\n");
    scanf("%d", &a);
    int S1[a] , bitA[10] , bitB[10];
    int i = 0;
    while (i < a)
    {

        printf("Enter element %d:", i + 1);

        scanf("%d", &c);
        for (int j = 0; j < a; j++)
        {
            if (c == S1[j])
            {
                printf("element already exists\n");
                printf("Enter element %d:", i + 1);
                scanf("%d", &c);
            }
        }
        for (int j = 0; j < 10; j++)
        {
            if (c == U[j])
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            
            }
        }
        if (flag == 0)
        {
            S1[i] = c;
            i++;
        }
        else if (flag == 1)
        {
            printf("Element does not exist in universal set\n");
        }
    }

    printf("\nFirst set S1=");
    for (int i = 0; i < a; i++)
    {
        printf("%d ", S1[i]);
    }
    printf("\nBitstring of first set: ");
    for(int i=0;i<10;i++){
        int flag1=0;
        for(int j=0;j<a;j++){
            if(S1[j]==U[i]){
                flag1=1;
                break;
            }
        }
        if(flag1==1){
            bitA[i]=1;
            
        }
        else{
            bitA[i]=0;
            
        }
        printf("%d",bitA[i]);
        
    }
    printf("\nEnter the size of second set\n");
    scanf("%d", &b);
    int S2[b],flag=0;
    i=0;
    while (i < b)
    {
        printf("Enter element %d:", i + 1);
        scanf("%d", &d);
        for (int j = 0; j < b; j++)
        {
            if (d== S2[j])
            {
                printf("element already exists\n");
                printf("Enter element %d:", i + 1);
                scanf("%d", &d);
            }
        }
        for (int j = 0; j < 10; j++)
        {
            if (d == U[j])
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            S2[i] = d;
            i++;
        }
        else if (flag == 1)
        {
            printf("Element does not exist in universal set\n");
        }
    }

    printf("\nSecond Set S2=");
    for (int i = 0; i < b; i++)
    {
        printf("%d ", S2[i]);
    }
    printf("\nBitstring of second set: ");
    for(int i=0;i<10;i++){
        int flag1=0;
        for(int j=0;j<b;j++){
            if(S2[j]==U[i]){
                flag1=1;
                break;
            }
        }
        if(flag1==1){
            bitB[i]=1;
            
        }
        else{
            bitB[i]=0;
            
        }
        printf("%d",bitB[i]);
        
    }
    int union1[10],intersection[10];
    printf("\nIntersection: ");
    for(int i=0;i<10;i++){
        if(bitA[i]==bitB[i]){
            intersection[i]=bitA[i];
        }
        else{
            intersection[i]=0;
        }
    printf("%d",intersection[i]);
    }
    printf("\nUnion: ");
    for(int i=0;i<10;i++){
        if(bitA[i]==bitB[i]){
            union1[i]=bitA[i];
        }
        else if(bitA[i]==1 || bitB[i]==1){
            union1[i]=1;
        }
    printf("%d",union1[i]);
    }
}
