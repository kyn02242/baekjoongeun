#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int min(int a, int b)
{
	if (a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int main()
{
	int arr[1000001] = {0};
	int i, j;
	int n;

	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	for (i = 4; i <= 1000000; i++)
	{
		if (i % 3 == 0)
		{
			arr[i] = min(arr[i - 1] + 1, arr[i / 3] + 1);
		}
		if (i % 2 == 0)
		{	
			if(arr[i]!=0){
				arr[i] = min(arr[i],min(arr[i - 1] + 1, arr[i / 2] + 1));
			}
			else{
				arr[i] = min(arr[i - 1] + 1, arr[i / 2] + 1);
			}
		}
		if (i % 2 != 0 && i % 3 != 0)
		{
			arr[i] = arr[i - 1] + 1;
		}
	}

	scanf("%d", &n);
	// for (i = 0; i < n; i++)
	// {
	// 	printf("%d ", arr[i]);
	// }

	printf("%d\n", arr[n]);

	return 0;
}
