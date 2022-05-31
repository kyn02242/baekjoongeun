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

int findmax(int arr[8001])
{
    int i;
    int max = 0;
    int cnt = 0;
    int index = 0;
    int brr[8001] = {0};
    for (i = 0; i < 8001; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index = i;
            cnt = 0;
            brr[cnt] = index;
        }
        if (arr[i] == max)
        {
            cnt++;
            brr[cnt] = i;
        }
    }
    qsort(brr, cnt + 1, sizeof(int), compare);
    if (cnt == 1)
    {
        return brr[1] - 4000;
    }
    return brr[2] - 4000;
}

int main()
{
    int n, m;
    int i, j;
    int l, r, mid;
    int arr[1000000];
    int max = 0;
    long long sum = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    l = 0;
    r = max;
    while (l + 1 < r)
    {
        sum = 0;
        mid = (l + r) / 2;
        for (i = 0; i < n; i++)
        {
            if (arr[i] - mid > 0)
            {
                sum += arr[i] - mid;
            }
        }
        if (sum > m)
        {
            l=mid;
        }
        else if(sum<m){
            r=mid;
        }
        else{
            printf("%d\n",mid);
            return 0;
        }
    }
    printf("%d\n",l);

    return 0;
}
