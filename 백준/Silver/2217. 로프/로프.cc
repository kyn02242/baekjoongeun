#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '₩n'
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> brr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		brr[i] = arr[i] * (n - i);
	}
	sort(brr.begin(), brr.end());
	cout << brr[n - 1];
}
