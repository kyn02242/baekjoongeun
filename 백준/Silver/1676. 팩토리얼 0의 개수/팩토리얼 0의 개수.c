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
    int n;
    int i;
    int cnt1=0;
    int cnt2=0;
    scanf("%d",&n);
    for(i=n;i>0;i--){
        if(i%5==0){
            if((i/5)%5==0){
                if(((i/5)/5)%5==0){
                    cnt1++;
                }
                cnt1++;
            }
            cnt1++;
        }
    }
    printf("%d\n",cnt1);

    return 0;
}
