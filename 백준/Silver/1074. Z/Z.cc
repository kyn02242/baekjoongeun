#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

int cnt(int n, int r, int c) {

	int half = pow(2, n - 1);

	if (n < 1) return 0;

	if (r < half && c < half) {
		return cnt(n - 1, r, c);
	}
	else if (r < half && c >= half) {
		return half*half + cnt(n - 1, r, c - half);
	}
	else if (r >= half && c < half) {
		return half * half * 2 + cnt(n - 1, r - half, c);
	}
	else {
		return half * half * 3 + cnt(n - 1, r - half, c - half);
	}
}


int main() {

	int n, r, c;

	scanf("%d %d %d", &n, &r, &c);

	printf("%d\n", cnt(n, r, c));

	return 0;
}

