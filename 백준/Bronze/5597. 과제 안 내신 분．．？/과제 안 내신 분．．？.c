#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char str1[51][51];

int main()
{
	int arr[30] = {0};
	int tmp;
	int i;
	for(i=0;i<28;i++){
		scanf("%d",&tmp);
		arr[tmp-1]++;
	}
	for(i=0;i<30;i++){
		if(arr[i]==0){
			printf("%d\n",i+1);
		}
	}
}
