#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	int n, a;
	int i;

	scanf("%d", &n);
	scanf("%d", &a);
	n /= 100;
	n *= 100;
	for (i = 0;; i++) {
		if ((n + i) % a == 0) {
			break;
		}
	}
	if (i < 10) {
		printf("0%d", i);
	}
	else {
		printf("%d", i);
	}
	return 0;
}
