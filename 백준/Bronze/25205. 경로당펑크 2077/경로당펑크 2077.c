#pragma warning(disable : 4996)
#include <stdio.h>
#include<stdlib.h>


int main()
{   
    char a;
    int i;
    int n;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++){
        scanf("%c",&a);
    }
    if(a=='y'||a=='u'||a=='o'||a=='p'||a=='h'||a=='j'||a=='k'||a=='l'||a=='b'||a=='n'||a=='m'||a=='O'||a=='P'||a=='m'||a=='i'){
        printf("0");
    }
    else{
        printf("1");
    }
    return 0;
}