#include <stdio.h>
#define MAX 100000
int Data[MAX][2] = {{0}};
int Count[MAX] = {0};
int isChild[MAX] = {0};
int ans = 0;
int n;
int DFS(int x)
{
    if (Count[x] == 0)
        return 0;
    else if (Count[x] == 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (Data[i][0] == x)
            {
                return DFS(Data[i][1]) + 1;
            }
        }
    }
    else
    {
        int max1 = 0, max2 = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (Data[i][0] == x)
            {
                int Result = DFS(Data[i][1]) + 1;

                if (Result > max1)
                {
                    int tmp = Result;
                    Result = max1;
                    max1 = tmp;
                }
                if (Result > max2)
                {
                    max2 = Result;
                }
            }
        }
        if (ans < max1 + max2)
            ans = max1 + max2;

        return max1;
    }
    return 0; //<-----
}
int main()
{
    printf("Input number of persons: ");
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n - 1; i++)
        {
            printf("Input row %d data: ", i + 1);
            scanf("%d %d", &Data[i][0], &Data[i][1]);
            Count[Data[i][0]] += 1;
            isChild[Data[i][1]] = 1;
        }
        int root;
        for (int i = 0; i < n; i++)
        {
            if (isChild[i] == 0)
            {
                root = i;
                break;
            }
        }
        int ResultRoot = DFS(root);
        if (ResultRoot > ans)
        {
            printf("%d", ResultRoot);
        }
        else
        {
            printf("%d", ans);
        }
        ans = 0;
        ResultRoot = 0;
        printf("\n");
    }
    return 0;
}