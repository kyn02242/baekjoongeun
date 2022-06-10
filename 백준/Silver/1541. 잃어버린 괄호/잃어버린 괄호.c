#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char str1[51][51];

int main()
{
	char str[51];
	int arr[51] ={0};
	int i,j;
	int tmp = 0;
	int sum =0;
	int n;
	int flag = 0;
	scanf("%s",str);
	n=strlen(str);
	for(i=0;i<n;i++){
		if(str[i] == '-'){
			for(j=tmp;j<i;j++){
				str1[flag][j-tmp] = str[j];
			}
			tmp = i+1;
			flag++;
		}
		if(i==n-1){
			for(j=tmp;j<=i;j++){
				str1[flag][j-tmp] = str[j];
			}
		}
	}
	for(i=0;i<=flag;i++){
		n=0;
		tmp = strlen(str1[i]);
		//printf("%d\n",tmp);
		for(j=0;j<tmp;j++){
			if(str1[i][j]>='0'&&str1[i][j]<='9'){
				n += str1[i][j]-'0';
				if(str1[i][j+1]!='+'&&j!=tmp-1){
					n*=10;
				}
			}
			if(str1[i][j]=='+'){
				arr[i]+=n;
				n=0;
			}
		}
		arr[i]+=n;
	}
	sum = arr[0];
	for(i=1;i<=flag;i++){
		sum-=arr[i];
	}
	printf("%d",sum);

	return 0;	
}
