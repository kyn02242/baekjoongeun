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

int arr[200002];
int flag = 0;

void insert() {
	int tmp;
	tmp = flag;
	int ntmp;
	while (1) {
		if (tmp == 1) {
			break;
		}
		else {
			if (abs(arr[tmp / 2]) < abs(arr[tmp])) {
				break;
			}
			else if (abs(arr[tmp / 2]) == abs(arr[tmp])) {
				if (arr[tmp / 2] > arr[tmp]) {
					ntmp = arr[tmp / 2];
					arr[tmp / 2] = arr[tmp];
					arr[tmp] = ntmp;
				}
			}
			else {
				ntmp = arr[tmp / 2];
				arr[tmp / 2] = arr[tmp];
				arr[tmp] = ntmp;
			}
		}
		tmp /= 2;
	}
}
void out() {
	int tmp = 1;
	int ntmp;
	while (1) {

		if (arr[tmp * 2] == 0 && arr[tmp * 2 + 1] == 0) {//아래 값이 없을때
			break;
		}

		else if (arr[tmp * 2] != 0 && arr[tmp * 2 + 1] == 0) {//아래 값이 하나만 있을때
			if (abs(arr[tmp * 2]) < abs(arr[tmp])) {
				ntmp = arr[tmp * 2];
				arr[tmp * 2] = arr[tmp];
				arr[tmp] = ntmp;
			}
			else if (abs(arr[tmp * 2]) == abs(arr[tmp])) {
				if (arr[tmp] > arr[tmp * 2]) {
					ntmp = arr[tmp * 2];
					arr[tmp * 2] = arr[tmp];
					arr[tmp] = ntmp;
				}
			}
			break;
		}

		else {//아래 값이 두개 다 있을때

			if (abs(arr[tmp * 2]) < abs(arr[tmp]) || abs(arr[tmp * 2 + 1]) < abs(arr[tmp])) {//둘 중 하나라도 더 작을때
				if (abs(arr[tmp * 2]) < abs(arr[tmp]) && abs(arr[tmp * 2 + 1]) < abs(arr[tmp])) {//둘 다 작을때
					if (abs(arr[tmp * 2]) > abs(arr[tmp * 2 + 1])) {//둘 중 뒤가 더 작을때
						ntmp = arr[tmp * 2 + 1];
						arr[tmp * 2 + 1] = arr[tmp];
						arr[tmp] = ntmp;
						tmp = tmp * 2 + 1;
					}
					else if (abs(arr[tmp * 2]) == abs(arr[tmp * 2 + 1])) {//둘이 같을때
						if (arr[tmp * 2] < arr[tmp * 2 + 1]) {
							ntmp = arr[tmp * 2];
							arr[tmp * 2] = arr[tmp];
							arr[tmp] = ntmp;
							tmp = tmp * 2;
						}
						else {
							ntmp = arr[tmp * 2 + 1];
							arr[tmp * 2 + 1] = arr[tmp];
							arr[tmp] = ntmp;
							tmp = tmp * 2 + 1;
						}
					}
					else {//둘 중 앞이 작을때
						ntmp = arr[tmp * 2];
						arr[tmp * 2] = arr[tmp];
						arr[tmp] = ntmp;
						tmp = tmp * 2;
					}
				}
				else if (abs(arr[tmp * 2]) < abs(arr[tmp])) {//앞에것만 작을때
					ntmp = arr[tmp * 2];
					arr[tmp * 2] = arr[tmp];
					arr[tmp] = ntmp;
					tmp = tmp * 2;
				}
				else {//뒤의것만 작을때
					ntmp = arr[tmp * 2 + 1];
					arr[tmp * 2 + 1] = arr[tmp];
					arr[tmp] = ntmp;
					tmp = tmp * 2 + 1;
				}
			}

			else if (abs(arr[tmp * 2]) == abs(arr[tmp]) || abs(arr[tmp * 2 + 1]) == abs(arr[tmp])) {//둘 중 같은게 하나라도 있을때
				if (abs(arr[tmp * 2]) == abs(arr[tmp]) && abs(arr[tmp * 2 + 1]) == abs(arr[tmp])) {//둘 다 같을때
					if (arr[tmp * 2] < arr[tmp] || arr[tmp * 2 + 1] < arr[tmp]) {
						ntmp = arr[tmp * 2];
						arr[tmp * 2] = arr[tmp];
						arr[tmp] = ntmp;
						tmp = tmp * 2;
					}
					else {
						break;
					}
				}
				else if (abs(arr[tmp * 2]) == abs(arr[tmp])) {//앞에것만 같을때
					if (arr[tmp * 2] < arr[tmp]) {
						ntmp = arr[tmp * 2];
						arr[tmp * 2] = arr[tmp];
						arr[tmp] = ntmp;
						tmp *= 2;
					}
					else {
						break;
					}
				}
				else {//뒤에것만 같을때
					if (arr[tmp * 2 + 1] < arr[tmp]) {
						ntmp = arr[tmp * 2 + 1];
						arr[tmp * 2 + 1] = arr[tmp];
						arr[tmp] = ntmp;
						tmp = tmp * 2 + 1;
					}
					else {
						break;
					}
				}
			}
			else {//모든 예외
				break;
			}

		}
	}

}


int main()
{
	int n;
	int i, tmp;
	int j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp == 0) {
			/*for (j = 0; j < flag + 1; j++) {
				printf("%d ",arr[j]);
			}
			printf("\n");*/
			if (flag == 0) {
				printf("0\n");
			}
			else if (flag == 1) {
				printf("%d\n", arr[1]);
				flag--;
			}
			else {
				printf("%d\n", arr[1]);
				arr[1] = arr[flag];
				arr[flag] = 0;
				flag--;
				out();
			}
		}
		else {
			if (flag == 0) {
				arr[1] = tmp;
				flag++;
			}
			else {
				flag++;
				arr[flag] = tmp;
				insert();
			}
		}
	}

	return 0;
}
