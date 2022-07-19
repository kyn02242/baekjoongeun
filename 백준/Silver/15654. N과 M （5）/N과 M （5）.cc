#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[9];
int brr[9];
int crr[9];

void fuck(int flag, int n, int m) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	if (flag == m) {
		for (int i = 0; i < m; i++) {
			cout << crr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (brr[i] == 0) {
			crr[flag] = arr[i];
			brr[i] = 1;
			fuck(flag+1, n, m);
			brr[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n>> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	fuck(0, n, m);
	
}
