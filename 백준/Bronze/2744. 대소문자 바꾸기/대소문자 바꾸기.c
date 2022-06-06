#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char str[101];
	int len;
	int i;
	scanf("%s", str);
	len = strlen(str);
	for (i = 0; i < len; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 'a' + 'A';
		}
		else {
			str[i] = str[i] - 'A' + 'a';
		}
	}
	printf("%s", str);
	return 0;
}