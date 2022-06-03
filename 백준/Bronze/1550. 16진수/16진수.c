#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;
	int i;
	unsigned int sum = 0;
	char str[7];
	scanf("%s",str);
	for(i=0;i<strlen(str);i++){
		if(str[i]=='0'){
			continue;
		}
		else if(str[i]>='0'&&str[i]<='9'){
			str[i] -= '0';
			sum += str[i]*(int)pow((double)16,(double)strlen(str)-i-1);
		}
		else{
			str[i] = str[i]-'A'+10;
			sum += str[i]*(int)pow((double)16,(double)strlen(str)-i-1);
		}
	}
	printf("%d\n",sum);

	return 0;
}