#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int arr[1001];
int brr[10000][2];
int m;

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 > num2)
	{
		return 1;
	}
	if (num1 < num2)
	{
		return -1;
	}
	return 0;
}

void dfs(int v)
{
	int min = 1001;
	int i, j;
	int crr[10000] = {0};
	int cnt = 0;
	printf("%d ", v);
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

void bfs(int v)
{
	int queue[1001] = {0};
	int l = 0;
	int r = 1;
	int i;
	int flag;
	queue[0] = v;
	while (l != r)
	{
		flag = r;
		for (i = 0; i < m; i++)
		{
			if (brr[i][0] == queue[l])
			{
				if (arr[brr[i][1]] == 0)
				{
					queue[r] = brr[i][1];
					arr[queue[r]] = 1;
					r++;
				}
			}
			else if (brr[i][1] == queue[l])
			{
				if (arr[brr[i][0]] == 0)
				{
					queue[r] = brr[i][0];
					arr[queue[r]] = 1;
					r++;
				}
			}
		}
	qsort(&queue[flag],r-flag,sizeof(int),compare);
	printf("%d ",queue[l]);
	arr[queue[l]]=1;
	l++;
	}
}

int main()
{
	int i;
	int v;
	scanf("%d %d %d", &n, &m, &v);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &brr[i][0], &brr[i][1]);
	}
	dfs(v);
	printf("\n");
	for (i = 0; i <= n; i++)
	{
		arr[i] = 0;
	}
	bfs(v);

	return 0;
}
