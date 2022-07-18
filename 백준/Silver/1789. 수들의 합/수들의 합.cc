#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int main()
{
	long long n;
	cin >> n;
	for (int i = 1;; i++) {
		if (i > n) {
			cout << i-1;
			break;
		}
		n -= i;
	}
}
