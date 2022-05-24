#pragma warning(disable : 4996)
#include <stdio.h>
#include<stdlib.h>


int main()
{   
    int flag=0;
    int arr[100000]={0};
    int n;
    int i;
    int tmp;
    int sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        if(tmp == 0){
            flag--;
            sum-=arr[flag];
        }
        else{
            arr[flag]=tmp;
            sum+=tmp;
            flag ++;
        }
    }
    printf("%d\n",sum);
}