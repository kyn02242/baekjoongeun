#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int main()
{
	int m, n;
	int j;
	int sum = 0;
	int flag = 0;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		for (j = 2; j < i; j++) {
			if (i % j == 0) {
				break;
			}
		}
		if (j == i) {
			sum += i;
			if (flag == 0) {
				flag = i;
			}
		}
	}
	if (sum == 0) {
		cout << -1;
	}
	else {
		cout << sum << endl << flag;
	}
}
