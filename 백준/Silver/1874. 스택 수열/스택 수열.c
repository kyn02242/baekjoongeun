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
    int n;
    int num=1;
    int arr[100001]={0};
    int flag = 0;
    int brr[100001]={0};
    int flag1 = -1;
    char crr[200002]={0};
    int flag2 = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    while(1){
        if(flag1==-1){
            flag1++;
            brr[flag1]=num;
            num++;
            crr[flag2] = '+';
            flag2++;
        }
        else if(arr[flag]>brr[flag1]){
            flag1++;
            brr[flag1]=num;
            num++;
            crr[flag2] = '+';
            flag2++;
        }
        else if(arr[flag]==brr[flag1]){
            flag1--;
            crr[flag2] = '-';
            flag2++;
            flag++;
        }
        else{
            printf("NO\n");
            return 0;
        }
        if(flag2==n*2){
            break;
        }
    }
    for(i=0;i<n*2;i++){
        printf("%c\n",crr[i]);
    }    
    return 0;
}
