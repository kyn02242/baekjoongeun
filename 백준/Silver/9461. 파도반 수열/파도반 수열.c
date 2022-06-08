#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	unsigned long long arr[101];
	int i;
	int n;
	int tmp;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	for (i = 5; i < 101; i++) {
		arr[i] = arr[i - 2] + arr[i - 3];
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		printf("%lld\n", arr[tmp]);
	}
	return 0;
}
