#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int arr[10]={1,2,4,7,13,24,44,81,149,274};
	int t,n;
	int i;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		printf("%d\n",arr[n-1]);
	}
	return 0;
}
