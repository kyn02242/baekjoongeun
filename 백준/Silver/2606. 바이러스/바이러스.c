#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int arr[100][2];
int brr[101];
int sum = 0;

void fuck(int a) {//0이면 옆도 0;
	int i;
	for (i = 0; i < a; i++) {
		if (arr[i][0] == 0) {
			arr[i][1] = 0;
		}
		if (arr[i][1] == 0) {
			arr[i][0] = 0;
		}
	}
}


int main()
{
	int i, j;
	int n;
	int a;
	int cnt = 0;
	int flag = 0;
	scanf("%d", &n);//컴퓨터 수
	scanf("%d", &a);//연결 수
	for (i = 0; i < a; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
		if (arr[i][0] == 1) {
			arr[i][0] = 0;
		}
		if (arr[i][1] == 1) {
			arr[i][1] = 0;
		}
	}
	for (i = 1; i <= n; i++) {
		brr[i] = 1;
	}
	brr[1] = 0;
	for (i = 0; i < a; i++) {
		if (arr[i][0] != 0 && arr[i][1] != 0) {
			if (i == a - 1) {
				if (flag == cnt) {
					break;
				}
				else {
					i = -1;
					flag = cnt;
					cnt = 0;
				}
			}
			continue;
		}
		else if (arr[i][0] != 0) {
			brr[arr[i][0]] = 0;
			for (j = 0; j < a; j++) {
				if (i == j) {
					continue;
				}
				if (arr[j][0] == arr[i][0]) {
					arr[j][0] = 0;
				}
				if (arr[j][1] == arr[i][0]) {
					arr[j][1] = 0;
				}
			}
			arr[i][0] = 0;
		}
		else if (arr[i][1] != 0) {
			brr[arr[i][1]] = 0;
			for (j = 0; j < a; j++) {
				if (i == j) {
					continue;
				}
				if (arr[j][0] == arr[i][1]) {
					arr[j][0] = 0;
				}
				if (arr[j][1] == arr[i][1]) {
					arr[j][1] = 0;
				}
			}
			arr[i][1] = 0;
		}		
		if (arr[i][0] == 0 && arr[i][1] == 0) {
			cnt++;
		}
		if (i == a-1) {
			if (flag == cnt) {
				break;
			}
			else {
				i = -1;
				flag = cnt;
				cnt = 0;
			}
		}
	}
	//printf("==\n");
	for (i = 0; i < a; i++) {
		if (arr[i][0] != 0) {
			brr[arr[i][0]] = 1;
		}
		if (arr[i][1] != 0) {
			brr[arr[i][1]] = 1;
		}
		//printf("%d %d\n", arr[i][0], arr[i][1]);
	}
	//printf("==\n");
	for (i = 1; i < n+1; i++) {
		//printf("%d ", brr[i]);
		if (brr[i] != 0) {
			sum++;
		}
	}
	printf("%d\n", n - sum - 1);
	return 0;
}
