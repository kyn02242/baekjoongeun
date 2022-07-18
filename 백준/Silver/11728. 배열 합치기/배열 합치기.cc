#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	int flag1 = 0, flag2 = 0;
	cin >> n >> m;
	vector<long long> arr(n+1, 1000000001);
	vector<long long> brr(m+1, 1000000001);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < m; i++) {
		cin >> brr[i];
	}
	sort(brr.begin(), brr.end());
	while (1) {
		if (arr[flag1] < brr[flag2]) {
			cout << arr[flag1] << " ";
			flag1++;
		}
		else {
			cout << brr[flag2] << " ";
			flag2++;
		}
		if (flag1 == n && flag2 == m) {
			break;
		}		
	}
}
