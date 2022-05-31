#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int n1 = *(int *)a;
    int n2 = *(int *)b;

    if (n1 < n2)
        return -1;
    if (n1 > n2)
        return 1;

    return 0;
}

int main()
{
    int i, j;
    int n, m;
    int cnt = 0;
    char str[500][500];
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++)
    {
        getchar();
        for (j = 0; j < m; j++)
        {
            scanf("%c", &str[i][j]);
            if (str[i][j] == 'W')
            {
                cnt++;
            }
        }
    }
    if (cnt == 0)
    {
        printf("1\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (str[i][j] == '.')
                {
                    printf("D");
                }
                else
                {
                    printf("%c", str[i][j]);
                }
            }
            printf("\n");
        }
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (str[i][j] == 'W')
            {
                if (i <= n - 1 && j <= m - 1)
                {
                    if (str[i + 1][j] == 'S' || str[i][j + 1] == 'S')
                    {
                        printf("0\n");
                        return 0;
                    }
                }
            }
            if (str[i][j] == 'S')
            {
                if (i <= n - 1 && j <= m - 1)
                {
                    if (str[i + 1][j] == 'W' || str[i][j + 1] == 'W')
                    {
                        printf("0\n");
                        return 0;
                    }
                }
            }
        }
    }
    printf("1\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (str[i][j] == '.')
            {
                printf("D");
            }
            else
            {
                printf("%c", str[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
