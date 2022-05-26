#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
    int i;
    int n, k;
    int cnt;
    int cnt2 = 0;
    int arr[1000] = {0};
    int flag = 0;
    scanf("%d %d", &n, &k);
    cnt = n;
    for (i = 0; i < n; i++)
    {
        arr[i] = 1;
    }

    printf("<");
    if (n != 1)
    {
        while (1)
        {
            for (i = flag;; i++)
            {
                if (arr[flag] == 1)
                {
                    cnt2++;
                }
                if (cnt2 == k)
                {
                    printf("%d, ", flag + 1);
                    arr[flag] = 0;
                    cnt--;
                    break;
                }
                flag++;
                if (flag == n)
                {
                    flag = 0;
                }
            }
            cnt2 = 0;
            if (cnt == 1)
            {
                break;
            }
        }
    }
        for (i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                printf("%d>", i + 1);
            }
        }
    return 0;
}