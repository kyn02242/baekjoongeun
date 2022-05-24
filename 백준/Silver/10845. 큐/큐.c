#pragma warning(disable : 4996)
#include <stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{   
    char str[6];
    int arr[10000]={0};
    int flag = 0;
    int cnt = 0;
    int i,tmp,n;
    int flag2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",str);
        switch(str[0]){
            case 'p':
                if(str[1]=='u'){
                    scanf("%d",&arr[flag]);
                    cnt++;
                    flag ++;
                }
                else{
                    if(flag==flag2){
                        printf("-1\n");
                    }
                    else{
                        printf("%d\n",arr[flag2]);
                        flag2++;
                        cnt--;
                    }
                }
                break;
            case 's':
                printf("%d\n",cnt);
                break;
            case 'e':
                if(cnt==0){
                    printf("1\n");
                }
                else{
                    printf("0\n");
                }
                break;
            case 'f':
                if(flag == flag2){
                    printf("-1\n");
                }
                else{
                    printf("%d\n",arr[flag2]);
                }
                break;
            case 'b':
                if(flag == flag2){
                    printf("-1\n");
                }
                else{
                    printf("%d\n",arr[flag-1]);
                }
                break;
        }
    }

}