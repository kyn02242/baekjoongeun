#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int n1 = *(int *)a;
    int n2 = *(int *)b;

    if (n1 < n2)
        return 1;
    if (n1 > n2)
        return -1;

    return 0;
}

int findmax(int arr[100], int n)
{
    int i;
    int max = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int cnt, n, m;
    int i, j, k;
    int arr[100] = {0};
    int ans,front,max;
    scanf("%d", &cnt);
    for (i = 0; i < cnt; i++)
    {
        scanf("%d %d", &n, &m);
        ans = 1;
        front = 0;
        max = 0;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }
        while (1)
        {
            max=findmax(arr,n);

            while (arr[front] != max)
            {
                front = (front + 1) % n;
            }
            if (front == m)
            {
                break;
            }
            arr[front] = 0;
            front = (front + 1) % n;
            max = 0;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
