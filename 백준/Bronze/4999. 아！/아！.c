#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int arr[1001];
int brr[10000][2];
int m;

int compare(const int* a, const int* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2) {
		return 1;
	}
	if (num1 < num2) {
		return -1;
	}
	return 0;
}



int main()
{
	int cnt = 0;
	char a[1000];
	char b[1000];
	int i;
	scanf("%s", a);
	scanf("%s", b);
	for (i = 0;; i++) {
		if (a[i] == 'h') {
			break;
		}
		else {
			cnt++;
		}
	}
	for (i = 0;; i++) {
		if (b[i] == 'h') {
			break;
		}
		else {
			cnt--;
		}
	}
	if (cnt >= 0) {
		printf("go\n");
	}
	else {
		printf("no\n");
	}


	return 0;
}
