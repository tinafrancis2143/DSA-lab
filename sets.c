#include <stdio.h>

int U[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int a, b, c,d, flag = 0, count = 0;
void main()
{
    printf("Enter the size of first set\n");
    scanf("%d", &a);
    int S1[a];
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
                count = count + 1;
            }
        }
        if (flag == 0)
        {
            S1[i] = c;
            i++;
        }
        else if (count == 10 && flag == 1)
        {
            printf("Element does not exist in universal set\n");
        }
    }

    printf("\nFirst set S1=");
    for (int i = 0; i < a; i++)
    {
        printf("%d ", S1[i]);
    }
    printf("\nEnter the size of second set");
    scanf("%d", &b);
    int S2[b];
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
            if (c == U[j])
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
                count = count + 1;
            }
        }
        if (flag == 0)
        {
            S2[i] = d;
            i++;
        }
        else if (count == 10 && flag == 1)
        {
            printf("Element does not exist in universal set\n");
        }
    }

    printf("\nSecond Set S2=");
    for (int i = 0; i < b; i++)
    {
        printf("%d ", S2[i]);
    }
}
