#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	int tmp;
	int arr[1001][3];
	int flag[3];
	arr[0][0] = 0;
	arr[0][1] = 0;
	arr[0][2] = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> flag[0] >> flag[1] >> flag[2];
		arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + flag[0];
		arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + flag[1];
		arr[i][2] = min(arr[i - 1][1], arr[i - 1][0]) + flag[2];
	}
	tmp = min(arr[n][0], arr[n][1]);
	cout << min(tmp, arr[n][2])<<endl;
}
