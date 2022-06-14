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
	char a[10];
	int i;
	int cnt = 0;
	for (i = 0; i < 3; i++) {
		scanf("%s", a);
		if (strcmp(a, "black") == 0) {
			cnt++;
			if (i == 1) {
				printf("0");
			}
		}
		else if (strcmp(a, "brown") == 0) {
			if (i != 2) {
				printf("1");
			}
			else {
				if (cnt != 2) {
					printf("0");
				}
			}
		}

		else if (strcmp(a, "red") == 0) {
			if (i != 2) {
				printf("2");
			}
			else {
				if (cnt != 2) {
					printf("00");
				}
			}
		}
		else if (strcmp(a, "orange") == 0) {
			if (i != 2) {
				printf("3");
			}
			else {
				if (cnt != 2) {
					printf("000");
				}
			}
		}
		else if (strcmp(a, "yellow") == 0) {
			if (i != 2) {
				printf("4");
			}
			else {
				if (cnt != 2) {
					printf("0000");
				}
			}
		}
		else if (strcmp(a, "green") == 0) {
			if (i != 2) {
				printf("5");
			}
			else {
				if (cnt != 2) {
					printf("00000");
				}
			}
		}
		else if (strcmp(a, "blue") == 0) {
			if (i != 2) {
				printf("6");
			}
			else {
				if (cnt != 2) {
					printf("000000");
				}
			}
		}
		else if (strcmp(a, "violet") == 0) {
			if (i != 2) {
				printf("7");
			}
			else {
				if (cnt != 2) {
					printf("0000000");
				}
			}
		}
		else if (strcmp(a, "grey") == 0) {
			if (i != 2) {
				printf("8");
			}
			else {
				if (cnt != 2) {
					printf("00000000");
				}
			}
		}
		else if (strcmp(a, "white") == 0) {
			if (i != 2) {
				printf("9");
			}
			else {
				if (cnt != 2) {
					printf("000000000");
				}
			}
		}
	}
	return 0;
}
