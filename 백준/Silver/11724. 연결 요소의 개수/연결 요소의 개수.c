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

int arr[1001];
int brr[500001][2];
int n, m;

void dfs(int v)
{
	int min = 1001;
	int i, j;
	int crr[10000] = { 0 };
	int cnt = 0;
	//printf("%d ", v);
	arr[v] = 1;
	for (i = 0; i < m; i++)
	{
		if (brr[i][0] == v)
		{
			if (arr[brr[i][1]] == 0)
			{
				crr[cnt] = brr[i][1];
				cnt++;
			}
		}
		else if (brr[i][1] == v)
		{
			if (arr[brr[i][0]] == 0)
			{
				crr[cnt] = brr[i][0];
				cnt++;
			}
		}
	}
	if (cnt == 0)
	{
		return;
	}
	else
	{
		qsort(crr, cnt, sizeof(int), compare);
		for (i = 0; i < cnt; i++)
		{
			if (arr[crr[i]] == 0)
			{
				dfs(crr[i]);
			}
		}
	}
	return;
}

int main()
{
	int i;
	int cnt = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &brr[i][0], &brr[i][1]);
	}
	for (i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}
