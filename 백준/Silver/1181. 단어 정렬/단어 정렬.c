#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) // 오름차순 비교 함수 구현
{
    int char1 = strlen((char *)a); // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int char2 = strlen((char *)b); // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (char1 < char2) // a가 b보다 작을 때는
        return -1;     // -1 반환

    if (char1 > char2) // a가 b보다 클 때는
        return 1;      // 1 반환

    return strcmp((char *)a, (char *)b); // a와 b가 같을 때는 0 반환
}

int main()
{
    int i, j;
    int n;
    char str[20000][51];
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }

    qsort(str, n, 51 * sizeof(char), compare);

    printf("%s\n",str[0]);

    for (i = 1; i < n; i++)
    {
        if (strcmp(str[i - 1], str[i]) != 0)
        {
            printf("%s\n", str[i]);
        }
    }

    return 0;
}