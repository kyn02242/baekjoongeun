#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


bool compare(int a, int b)
{
	return a > b;
}

int main() {
	long long sum = 0, n;
	cin >> n;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(),compare);
	for (int i = 0; i < n; i++) {
		if (arr[i] - i > 0) {
			sum += arr[i] - i;
		}
	}
	cout << sum;



}
