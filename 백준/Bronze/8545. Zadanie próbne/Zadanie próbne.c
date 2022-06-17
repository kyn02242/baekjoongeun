#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int arr[1001];
int brr[10000][2];
int m;

int compare(const int* a, const int* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2) {
		return 1;
	}
	if (num1 < num2) {
		return -1;
	}
	return 0;
}



int main()
{
	int i;
	char arr[4];
	scanf("%s", arr);
	for (i = 2; i >= 0; i--) {
		printf("%c", arr[i]);
	}

	return 0;
}
