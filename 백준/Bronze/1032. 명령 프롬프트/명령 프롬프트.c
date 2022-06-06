#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char str[50][51];
	char ans[51] = { 0 };
	int i, j;
	int n;
	int len = 0;
	char tmp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	len = strlen(str[0]);
	for (i = 0; i < len; i++) {
		for (j = 0; j < n; j++) {
			tmp = str[0][i];
			if (str[j][i] != tmp) {
				ans[i] = '?';
			}
		}
		if (ans[i] != '?') {
			ans[i] = tmp;
		}
	}
	printf("%s", ans);
	return 0;
}