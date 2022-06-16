#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char str1[51][51];

int main()
{
	int tmp;
	int i;
	int sum=0;
	
	for(i=0;i<5;i++){
		scanf("%d",&tmp);
		sum+=tmp;
	}
	printf("%d",sum);
	return 0;
}
