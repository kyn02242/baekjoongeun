#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


bool compare(int a, int b)
{
	return a > b;
}

int main() {
	int n, m;
	int sum = 0;
	int a, b;
	cin >> n >> m;
	vector<int> arr(m);
	vector<int> brr(m);
	for (int i = 0; i < m; i++) {
		cin >> arr[i] >> brr[i];
	}
	
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());
	/*for (int i = 0; i < m; i++) {
		cout << arr[i] << " " << brr[i] << endl;
	}
	cout << "end" << endl;*/
	//cout << arr[0] << " " << brr[0] << endl;
	if (arr[0] == brr[0] * 6) {
		cout << brr[0] * n << endl;
		//cout << "1" << endl;
	}
	else if (arr[0]>brr[0]*6) {
		cout << brr[0] * n << endl;
		//cout << "2" << endl;
	}
	else {
		sum += arr[0] * (n / 6);
		//cout << sum << ": sum" << endl;
		if (n % 6 == 0) {
			cout << sum << endl;
			//cout << "3" << endl;
		}
		else {
			sum += min((n - ((n / 6) * 6)) * brr[0], arr[0]);
			/*cout << (n - ((n / 6) * 6)) * brr[0] << " " << arr[0] << endl;
			cout << brr[0] << endl;*/
			cout << sum << endl;
			//cout << "4" << endl;
		}
	}



}
