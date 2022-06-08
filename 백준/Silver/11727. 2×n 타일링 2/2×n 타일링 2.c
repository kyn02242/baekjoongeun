#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	unsigned long long arr[1001];
	int n, i;
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 3;
	arr[3] = 5;
	arr[4] = 11;
	arr[5] = 21;
	arr[6] = 39;
	for (i = 4; i < 1001; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]*2) % 10007;
	}
	scanf("%d", &n);
	printf("%d", arr[n]);


	return 0;
}
