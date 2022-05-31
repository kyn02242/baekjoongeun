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


int main()
{
    int i,j;
    int n,m;
    int b;
    int min = 100000000;
    int mini;
    int arr[250000];
    int sum = 0;
    int tmp;
    scanf("%d %d %d",&n,&m,&b);
    
    for(i=0;i<n*m;i++){
        scanf("%d",&arr[i]);
    }
    for(j=256;j>=0;j--){
        sum = 0;
        tmp = b;
        for(i=0;i<n*m;i++){
            if(arr[i]>j){
                sum+=2*(arr[i]-j);
                tmp+=arr[i]-j;
            }
            else if(arr[i]<j){
                sum+=j-arr[i];
                tmp-=j-arr[i];
            }
        }
        if(tmp>=0){
            if(min>sum){
                min = sum;
                mini = j;
            }
        }
    }
    printf("%d %d",min,mini);
    return 0;
}
