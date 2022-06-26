#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const int* a, const int* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2) {
		return -1;
	}
	if (num1 < num2) {
		return 1;
	}
	return 0;
}

int main()
{
	int i, n;
	int arr[21];
	scanf("%d", &n);
	arr[0] = 0;
	arr[1] = 1;
	for (i = 2; i < n+1; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	printf("%d", arr[n]);
}
