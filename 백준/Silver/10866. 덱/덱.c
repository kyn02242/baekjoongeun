#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int arr[30000] = {0};
    int flag1 = 15000;
    int flag2 = 15001;
    int i, tmp, n;
    int cnt = 0;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        char str[12];
        scanf("%s", str);
        switch (str[0])
        {
        case 'p':
            if (str[1] == 'u')
            { // push
                if (str[5] == 'f')
                { // front
                    scanf("%d", &tmp);
                    if (cnt==0)
                    {
                        arr[flag1] = tmp;
                        cnt++;
                        flag1--;
                    }
                    else{
                        arr[flag1] = tmp;
                        cnt++;
                        flag1--;
                    }
                }
                else
                { // back
                    scanf("%d", &tmp);
                    if (cnt==0)
                    {
                        arr[flag2] = tmp;
                        cnt++;
                        flag2++;
                    }
                    else{
                        arr[flag2] = tmp;
                        cnt++;
                        flag2++;
                    }
                }
            }
            else
            {                      // pop
                if (str[4] == 'f') // front
                {
                    if (cnt==0)
                    { //덱 비었을 때
                        printf("-1\n");
                    }
                    else
                    {
                        printf("%d\n", arr[flag1+1]);
                        cnt--;
                        flag1++;
                    }
                }
                else
                { // back
                    if (cnt==0)
                    { //덱 비었을 때
                        printf("-1\n");
                    }
                    else
                    {
                        printf("%d\n", arr[flag2-1]);
                        cnt--;
                        flag2--;
                    }
                }
            }
            break;
        case 's':
            printf("%d\n", cnt);
            break;
        case 'e':
            if (cnt == 0)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
            break;
        case 'f':
            if (cnt==0)
            { //덱 비었을 때
                printf("-1\n");
            }
            else
            {
                printf("%d\n", arr[flag1 + 1]);
            }
            break;
        case 'b':
            if (cnt==0)
            { //덱 비었을 때
                printf("-1\n");
            }
            else
            {
                printf("%d\n", arr[flag2 - 1]);
            }
            break;
        }
    }
    return 0;
}