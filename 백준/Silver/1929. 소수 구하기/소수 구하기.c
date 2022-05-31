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

int main()
{
    int i,j;
    int m,n;
    int arr[1000002] = {0};
    for(i=1;i<1000002;i++){
        if(arr[i]!=1){
            for(j=2;j*(i+1)<1000002;j++){
                arr[j*(i+1)-1] = 1;
            }
        }
    }
    arr[0]=1;
    scanf("%d %d",&m,&n);
    for(i=m-1;i<n;i++){
        if(arr[i]==0){
            printf("%d\n",i+1);
        }
    }
    // for(i=0;i<1000002;i++){
    //     if(arr[i]==0){
    //         printf("%d ",i+1);
    //     }
    // }
    return 0;
}
