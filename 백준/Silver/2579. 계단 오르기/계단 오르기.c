#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
	if (a < b) {
		return b;
	}
	else {
		return a;
	}
}

int main()
{
	int arr[301];
	int brr[301];
	int i, j;
	int n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	brr[0] = 0;
	brr[1] = arr[1];
	brr[2] = arr[1] + arr[2];
	for (i = 3; i <= n; i++) {
		brr[i] = arr[i] + max(brr[i - 2], arr[i - 1] + brr[i - 3]);
	}
	printf("%d", brr[n]);

	return 0;
}
