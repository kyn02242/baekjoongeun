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
	int n;
	for (int j = 0;;j++) {
		string  tmp1;
		cin >> n;
		if (n == 0) {
			break;
		}
		getline(cin, tmp1);
		vector<string> arr(n);
		vector<int> brr(n);
		for (int i = 0; i < n; i++) {
			getline(cin, arr[i]);
			//cout << "=========" << endl;
		}
		/*cout << arr[0] << endl;
		cout << arr[1] << endl;
		cout << arr[2] << endl;*/
		for (int i = 0; i < 2 * n - 1; i++) {
			int tmp;
			char tmp2[4];
			cin >> tmp;
			cin.getline(tmp2, 4, '\n');
			brr[tmp - 1]++;
		}
		for (int i = 0; i < n; i++) {
			if (brr[i] != 2) {
				cout <<j+1<<" " << arr[i] << endl;
				break;
			}
		}
	}
}
