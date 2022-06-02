#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct set
{
	char str1[21];
	char str2[21];
} set;

int compare(const void *a, const void *b) // 오름차순 비교 함수 구현
{

	return strcmp(((set *)a)->str1, ((set *)b)->str1);
}

int main()
{
	int i, j;
	int r, l;
	int mid = 1;
	int a, b;
	char tmp[21];
	struct set arr[100000];

	scanf("%d %d", &a, &b);

	for (i = 0; i < a; i++)
	{
		scanf("%s", arr[i].str1);
		scanf("%s", arr[i].str2);
	}

	qsort((set *)arr, a, sizeof(set), compare);

	for (i = 0; i < b; i++)
	{	
		l=0;
		r=a-1;
		scanf("%s",tmp);
		while (l+1<r)
		{
			mid = (r+l)/2;
			if(strcmp(tmp,arr[mid].str1)>0){
				l=mid;
			}
			else if(strcmp(tmp,arr[mid].str1)<0){
				r=mid;
			}
			else{
				break;
			}
		}
		if(strcmp(tmp,arr[mid].str1)==0){
			printf("%s\n",arr[mid].str2);
		}
		else if(strcmp(tmp,arr[r].str1)==0){
			printf("%s\n",arr[r].str2);
		}
		else{
			printf("%s\n",arr[l].str2);
		}
	}

	return 0;
}