#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int compare(const void *a, const void *b) // 오름차순 비교 함수 구현
{
    int n1 = *(int *)a; // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int n2 = *(int *)b; // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (n1<n2) // a가 b보다 작을 때는
        return -1;     // -1 반환

    if (n1>n2) // a가 b보다 클 때는
        return 1;      // 1 반환

    return 0; // a와 b가 같을 때는 0 반환
}

int main()
{
    int i;
    long long l,r,mid;
    int n,m;
    int arr[100000]={0};
    int max = 0;
    int tmp;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(max<arr[i]){
            max = arr[i];
        }
    }
    qsort(arr,n,sizeof(int),compare);

    
    
    scanf("%d",&m);

    for(i=0;i<m;i++){
        scanf("%d",&tmp);
        l=0;
        r=n-1;
        while(l+1<r){
            mid = (r+l)/2;
            if(arr[mid]<tmp){
                l=mid;
            }
            else if(arr[mid]>tmp){
                r=mid;
            }
            else if(arr[mid]==tmp||arr[r]==tmp||arr[l]==tmp){
                break;
            }
        }
        if(arr[mid]==tmp||arr[r]==tmp||arr[l]==tmp){
                printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    
    return 0;
}