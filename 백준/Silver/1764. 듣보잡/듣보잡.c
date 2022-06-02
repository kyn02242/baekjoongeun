#pragma warning(disable : 4996)

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int compare(const void *a, const void *b) // 오름차순 비교 함수 구현
{
	return strcmp((char *)a,(char *)b);
}

int i, j;

int a, b;

char str[500000][21] = {0};

char str2[500000][21] = {0};

long long arr[500000] = {0};

long long arr2[500000] = {0};

int arr3[500000] = {0};

int sum = 0;

int main()
{

	scanf("%d %d", &a, &b);

	for (i = 0; i < a; i++)
	{
		scanf("%s", str[i]);
	}
	qsort(str,a,21*sizeof(char),compare);
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < strlen(str[i]); j++)
		{
			arr[i] += str[i][j];
			arr[i] *= 31;
		}
		arr[i] %= 1234567891;
	}

	for (i = 0; i < b; i++)
	{
		scanf("%s", str2[i]);
	}

	qsort(str2,b,21*sizeof(char),compare);

	for (i = 0; i < b; i++)
	{
		for (j = 0; j < strlen(str2[i]); j++)
		{
			arr2[i] += str2[i][j];
			arr2[i] *= 31;
		}
		arr2[i] %= 1234567891;
	}

	// for(i=0;i<a;i++){
	// 	printf("%s\n",str[i]);
	// }

	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{

			if (arr[i] == arr2[j])
			{
				arr3[sum] = i;
				sum++;
			}
		}
	}

	printf("%d\n", sum);
	for (i = 0; i < sum; i++)
	{
		printf("%s\n", str[arr3[i]]);
	}

	return 0;
}