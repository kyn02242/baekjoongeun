#pragma warning(disable : 4996)
#include <stdio.h>
#include<stdlib.h>

int arr[20000001];

int main()
{   
    int n,m;
    int i;
    int tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        arr[tmp+10000000]++;
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&tmp);
        printf("%d ",arr[tmp+10000000]);
    }
}