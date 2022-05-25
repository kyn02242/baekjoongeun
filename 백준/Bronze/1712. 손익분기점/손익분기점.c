#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>


int main() {
	int a, b, c;
	int i;
	scanf("%d %d %d", &a, &b, &c);
	if (b >= c) {
		printf("-1\n");
		return 0;
	}
	printf("%d", (a / (c - b)) + 1);
	return 0;
}