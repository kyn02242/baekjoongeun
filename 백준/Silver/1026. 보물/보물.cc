#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


bool compare(int a, int b)
{
	return a > b;
}

int main() {
	int n;
	int sum = 0;
	cin >> n;
	vector<int> arr(n);
	vector<int> brr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> brr[i];
	}
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end(),compare);
	for (int i = 0; i < n; i++) {
		sum += arr[i] * brr[i];
	}
	cout << sum;

}
