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
	
	int n, m;
	int cnt=0;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int sum=0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			if (sum == m) {
				cnt++;
				break;
			}
			else if (sum > m) {
				break;
			}
		}
	}
	cout << cnt;


}
