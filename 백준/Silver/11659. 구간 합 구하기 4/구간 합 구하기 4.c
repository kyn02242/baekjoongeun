#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	int arr[100000];
	unsigned long long brr[100000];
	int n, m;
	int i, j;
	int tmp1;
	int tmp2;
	brr[0] = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (i == 0) {
			brr[0] = arr[0];
		}
		if (i > 0) {
			brr[i] = brr[i - 1] + arr[i];
		}
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d", &tmp1, &tmp2);
		if (tmp1 == 1) {
			printf("%lld\n", brr[tmp2 - 1]);
		}
		else {
			printf("%lld\n", brr[tmp2 - 1] - brr[tmp1 - 2]);
		}
	}

	return 0;
}
