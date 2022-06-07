#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	char tmp[21] = { 0 };
	char tmp1[21] = { 0 };
	char str[30][21];
	int arr[30] = { 0 };
	int i, j, k, t;
	int n;
	int flag = 0;
	int sum = 1;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		sum = 1;
		flag = 0;
		for (j = 0; j < 30; j++) {
			arr[j] = 0;
		}
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			scanf("%s %s", tmp, tmp1);
			if (j == 0) {
				strcpy(str[0], tmp1);
				arr[0]++;
				flag++;
			}
			else {
				for (k = 0; k < flag; k++) {
					if (strcmp(str[k], tmp1) == 0) {
						arr[k]++;
						break;
					}
				}
				if (k == flag) {
					strcpy(str[flag], tmp1);
					arr[flag]++;
					flag++;
				}
			}
		}//입력 완료

		/*for (j = 0; j < flag; j++) {
			printf("%s %d\n", str[j], arr[j]);
		}*/

		for (j = 0; j < flag; j++) {
			sum *= (arr[j] + 1);
		}
		printf("%d\n", sum - 1);


		
	}
	return 0;
}
