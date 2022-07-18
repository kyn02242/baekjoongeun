#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	int cnt = 0;
	int flag = 64;
	cin >> n;
	if (n == 64) {
		cout << 1;
	}
	else {
		while (1) {
			flag /= 2;
			if (n >= flag) {
				n -= flag;
				cnt++;
			}
			if (n == 0) {
				cout << cnt;
				break;
			}
		}
	}
}
