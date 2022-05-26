#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
    int i, j;
    int n, k;
    long long l, r;
    int max = 0;
    long long mid;
    int cnt = 0;
    int arr[10000] = {0};
    scanf("%d %d", &k, &n);
    for (i = 0; i < k; i++)
    {
        scanf("%d", &arr[i]);
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    l = 0;
    r = max;
    while (l + 1 < r)
    {
        mid = (r + l) / 2;
        for (i = 0; i < k; i++)
        {
            cnt += arr[i] / mid;
        }
        if (cnt >= n)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
        cnt = 0;
    }
    for (i = r;; i--)
    {
        cnt=0;
        for (j = 0; j < k; j++)
        {
            cnt += arr[j] / i;
        }
        if(cnt>=n){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}