#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;

	if (n1 < n2)
		return -1;
	if (n1 > n2)
		return 1;

	return 0;
}

int main() {
	int n;
	int arr[1000];
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), compare);

	for (i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}