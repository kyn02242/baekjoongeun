#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int arr[25][25];
int cnt[625];
int flag = 0;

int compare(const void *a, const void *b)
{
	int n1 = *(int *)a;
	int n2 = *(int *)b;
	if (n1 > n2)
	{
		return 1;
	}
	if (n1 < n2)
	{
		return -1;
	}

	return 0;
}

void check(int n, int m, int a)
{
	arr[n][m] = 2;
	cnt[flag]++;
	if (n != 0)
	{
		if (arr[n - 1][m] == 1)
		{
			check(n - 1, m, a);
		}
	}
	if (m != 0)
	{
		if (arr[n][m - 1] == 1)
		{
			check(n, m - 1, a);
		}
	}
	if (n != a-1)
	{
		if (arr[n + 1][m] == 1)
		{
			check(n + 1, m, a);
		}
	}
	if (m != a-1)
	{
		if (arr[n][m + 1] == 1)
		{
			check(n, m + 1, a);
		}
	}
}

int main()
{
	int n;
	char str[26];
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", str);
		for (j = 0; j < n; j++)
		{
			arr[i][j] = str[j] - '0';
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				check(i, j, n);
				flag++;
			}
		}
	}

	if (flag == 0)
	{
		printf("0\n");
	}
	else
	{
		qsort(cnt, flag, sizeof(int), compare);
		printf("%d\n", flag);
		for (i = 0; i < flag; i++)
		{
			printf("%d\n", cnt[i]);
		}
	}
	return 0;
}
