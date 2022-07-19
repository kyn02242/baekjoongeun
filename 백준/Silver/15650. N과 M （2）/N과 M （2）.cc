#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[9];
int brr[9];

void fuck(int flag, int cnt, int n, int m) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = flag; i <= n; i++) {
		if (brr[i] == 0) {
			brr[i] = 1;
			arr[cnt] = i;
			fuck(i + 1, cnt + 1, n, m);
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
	fuck(1, 0, n, m);
	
}
