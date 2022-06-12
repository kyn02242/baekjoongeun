#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	char arr[3];
	scanf("%s", &arr);
	if (arr[0] == 'A') {
		if (arr[1] == '+') {
			printf("4.3");
		}
		else if(arr[1]=='0') {
			printf("4.0");
		}
		else {
			printf("3.7");
		}
	}
	else if (arr[0] == 'B') {
		if (arr[1] == '+') {
			printf("3.3");
		}
		else if (arr[1] == '0') {
			printf("3.0");
		}
		else {
			printf("2.7");
		}
	}
	else if (arr[0] == 'C') {
		if (arr[1] == '+') {
			printf("2.3");
		}
		else if (arr[1] == '0') {
			printf("2.0");
		}
		else {
			printf("1.7");
		}
	}
	else if (arr[0] == 'D') {
		if (arr[1] == '+') {
			printf("1.3");
		}
		else if (arr[1] == '0') {
			printf("1.0");
		}
		else {
			printf("0.7");
		}
	}
	else {
		printf("0.0");
	}

	
	return 0;
}
