#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char str1[51][51];

int main()
{
	char str[1001];
	int i;
	int n;
	int len;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",str);
		len = strlen(str);
		printf("%c%c\n",str[0],str[len-1]);
	}
	return 0;	
}
