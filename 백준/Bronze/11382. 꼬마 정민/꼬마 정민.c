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
	long long a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld", a + b + c);
	return 0;
}
