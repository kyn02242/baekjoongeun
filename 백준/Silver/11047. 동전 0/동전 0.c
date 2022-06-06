#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int n, k;
	int i, j;
	int flag = -1;
	int arr[10];
	int cnt=0;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (i > 0 && arr[i - 1] < k && arr[i]>k) {
			flag = i - 1;
		}
		else if (arr[i] == k) {
			flag = i;
		}
	}
	if (flag == -1) {
		flag = n - 1;
	}
	while (k > 0) {
		k -= arr[flag];
		cnt++;
		if (k == 0) {
			printf("%d", cnt);
			break;
		}
		else if (k >= arr[flag]) {
			continue;
		}
		else {
			while (arr[flag] > k) {
				flag--;
			}
		}
	}
	return 0;
}