#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main() {
	int sum = 0;
	int tmp;
	int i;
	for (i = 0; i < 4; i++) {
		scanf("%d", &tmp);
		sum += tmp;
	}
	printf("%d\n", sum / 60);
	printf("%d", sum % 60);
	return 0;
}