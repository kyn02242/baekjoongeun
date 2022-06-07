#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a,const void* b){
	int a1= *(int *)a;
	int b1= *(int *)b;

	if(a1>b1){
		return 1;
	}
	else if(b1>a1){
		return -1;
	}
	else{
		return 0;
	}
}

int main()
{
	int n;
	int i,j;
	int arr[1001];
	int sum = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	qsort(arr,n,sizeof(int),compare);

	for(i=0;i<n;i++){
		sum+=arr[i]*(n-i);
	}

	printf("%d\n",sum);
	return 0;
}
