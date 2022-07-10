#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	long long arr[10005][2];
	double sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 0; i < n - 1; i++) {
		sum += 0.5 * (arr[0][0] * arr[i][1] + arr[i][0] * arr[i + 1][1] + arr[i + 1][0] * arr[0][1] - arr[i][0] * arr[0][1] - arr[i + 1][0] * arr[i][1] - arr[0][0] * arr[i + 1][1]);
	}
	cout << fixed;
	cout.precision(1);
	if (sum >= 0) {
		cout << sum << endl;
	}
	else {
		cout << -1 * sum << endl;
	}
}
