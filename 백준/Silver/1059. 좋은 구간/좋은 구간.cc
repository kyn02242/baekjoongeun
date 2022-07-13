#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	int m;
	int tmp;
	int sum = 0;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	//for (int i = 0; i < n; i++) {
	//	cout << arr[i] << endl;
	//}
	
	cin >> m;
	for (int i = 0; i < n; i++) {
		if (arr[i] == m) {
			cout << 0 << endl;
			return 0;
		}
		else if (i == n - 1 && arr[i] < m) {
			cout << 0 << endl;

			return 0;
		}
		else if (i == 0 && arr[i] > m) {

			for (int i = 1; i < arr[0]; i++) {
				for (int j = i + 1; j < arr[0]; j++) {
					if (m >= i && m <= j) {
						//cout << "[" << i << "," << j << "]" << endl;
						sum++;
					}
				}
			}
			cout << sum << endl;
			return 0;
		}
		else {
			if (arr[i]<m && arr[i + 1]>m) {
				tmp = i;
				break;
			}
		}
	}


	for (int i = arr[tmp] + 1; i < m + 1; i++) {
		for (int j = i + 1; j < arr[tmp + 1]; j++) {
			if (m >= i && m <= j) {
				//cout << "[" << i << "," << j << "]" << endl;
				sum++;
			}
		}
	}
	cout << sum<<endl;
}
