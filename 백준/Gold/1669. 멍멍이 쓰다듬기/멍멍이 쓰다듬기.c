#include <stdio.h>

int main()
{
    int t,i,j;
    int a,b;
    int num = 1;
    int cnt = 0;
        num = 1;
        cnt = 0;
        scanf("%d %d",&a,&b);
        b=b-a;
    if(b==0){
        printf("0\n");
        return 0;
    }
        for(j=0;;j++){
            if(b>2*num){
                b-=2*num;
                cnt+=2;
                num++;
            }
            else if(b>num){
                cnt+=2;
                break;
            }
            else if(b<=num){
                cnt++;
                break;
            }
        }
        printf("%d\n",cnt);
 

    return 0;
}