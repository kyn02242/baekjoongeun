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

int findmax(int arr[8001]){
    int i;
    int max = 0;
    int cnt = 0;
    int index = 0;
    int brr[8001]={0};
    for(i=0;i<8001;i++){
        if(arr[i]>max){
            max = arr[i];
            index = i;
            cnt = 0;
            brr[cnt] = index;
        }
        if(arr[i]==max){
            cnt++;
            brr[cnt] = i;
        }
    }
    qsort(brr,cnt+1,sizeof(int),compare);
    if(cnt==1){
        return brr[1]-4000;
    }
    return brr[2]-4000;
}

int main()
{
    int i,j;
    int n;
    int tmp;
    int arr[8001]={0};
    int brr[500000] = {0};
    int max = -4001;
    int min = 4001;
    double avg=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        arr[tmp+4000]++;
        brr[i]=tmp;
        if(tmp>max){
            max=tmp;
        }
        if(tmp<min){
            min = tmp;
        }
        avg+=(double)tmp/(double)n;
    }
    qsort(brr,n,sizeof(int),compare);

    if(avg>0){
    avg += 0.5;
    }
    else{
        avg*=-1;
        avg+=0.5;
        avg*=-1;
    }  

    printf("%d\n",(int)avg);
    printf("%d\n",brr[n/2]);
    printf("%d\n",findmax(arr));
    printf("%d\n",max-min);

    return 0;
}
