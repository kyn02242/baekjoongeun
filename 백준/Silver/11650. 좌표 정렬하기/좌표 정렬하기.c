#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) // 오름차순 비교 함수 구현
{
    int *n1 = (int *)a; // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int *n2 = (int *)b; // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (n1[0]<n2[0]) // a가 b보다 작을 때는
        return -1;     // -1 반환

    if (n1[0]>n2[0]) // a가 b보다 클 때는
        return 1;      // 1 반환

    if (n1[1]<n2[1]) // a가 b보다 작을 때는
        return -1;     // -1 반환

    if (n1[1]>n2[1]) // a가 b보다 클 때는
        return 1;      // 1 반환

    return 0; // a와 b가 같을 때는 0 반환
}

int main()
{
    int i;
    int arr[100000][2];
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }
    qsort(arr,n,2*sizeof(int),compare);

    for(i=0;i<n;i++){
        printf("%d %d\n",arr[i][0],arr[i][1]);
    }
    
    return 0;
}