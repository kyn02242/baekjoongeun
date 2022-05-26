#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct wtf{
    int age;
    char name[101];
}wtf;

wtf arr[100000];

int compare(const void *a, const void *b) // 오름차순 비교 함수 구현
{
    wtf n1 = *(wtf *)a; // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    wtf n2 = *(wtf *)b; // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (n1.age<n2.age) // a가 b보다 작을 때는
        return -1;     // -1 반환

    if (n1.age>n2.age) // a가 b보다 클 때는
        return 1;      // 1 반환

    return 0; // a와 b가 같을 때는 0 반환
}

int main()
{
    int i;
    
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %s",&arr[i].age,arr[i].name);
    }
    qsort(arr,n,sizeof(wtf),compare);

    for(i=0;i<n;i++){
        printf("%d %s\n",arr[i].age,arr[i].name);
    }
    
    return 0;
}