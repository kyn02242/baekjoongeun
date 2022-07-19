#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


bool up(int a, int b) {
	return a > b;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, sc, p;
	int flag = 1;
	cin >> n >> sc >> p;
	if (n == 0) {
		cout << 1;
	}
	else {
		vector<int> arr(n,0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end(), up);
		if (arr.back() >= sc && arr.size() == p) {
			cout << "-1";
		}
		else {
			arr.push_back(sc);
			sort(arr.begin(), arr.end(), up);
			for (int i = 0; i < n + 1; i++) {
				if (arr[i] == sc) {
					cout << i + 1;
					return 0;
				}
			}
			cout << 1;
		}
	}
}
