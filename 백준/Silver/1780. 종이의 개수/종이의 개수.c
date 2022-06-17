#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int arr[2187][2187];
int cnt1 = 0;
int cnt2 = 0;
int cnt3 = 0;

void check(int n, int a, int b) {//a,b가 제일 위 왼쪽 값의 인덱스인 길이가 n인 사각형에서 판별
	int i, j;
	int flag = arr[a][b];
	int cnt = 0;
	if (flag >= 2) {
		return 0;
	}
	for (i = a; i < a + n; i++) {
		for (j = b; j < b + n; j++) {
			if (arr[i][j] == flag) {
				cnt++;
			}
		}
	}
	if (cnt == n * n) {
		if (flag == -1) {
			for (i = a; i < a + n; i++) {
				for (j = b; j < b + n; j++) {
					arr[i][j] = 2;
				}
			}
			cnt1++;
		}
		else if (flag == 0) {
			for (i = a; i < a + n; i++) {
				for (j = b; j < b + n; j++) {
					arr[i][j] = 3;
				}
			}
			cnt2++;
		}
		else {
			for (i = a; i < a + n; i++) {
				for (j = b; j < b + n; j++) {
					arr[i][j] = 4;
				}
			}
			cnt3++;
		}
		return;
	}
	else {
		return;
	}
}





int main()
{
	int n;
	int cnt = 0;
	int i, j;
	int tmp;
	scanf("%d", &n);
	tmp = n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	while (tmp!=0) {
		for (i = 0; i < n / tmp; i++) {
			for (j = 0; j < n / tmp; j++) {
				check(tmp, i * tmp, j * tmp);
			}
		}
		tmp /= 3;
	}
	
	printf("%d\n%d\n%d", cnt1, cnt2, cnt3);
	return 0;
}
