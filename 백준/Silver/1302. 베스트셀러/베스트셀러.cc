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
	
	map<string, int> m;
	string tmp;
	int n,max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		m[tmp]++;
	}
	for (auto i = m.begin(); i != m.end(); i++) {
		if (i->second > max) {
			max = i->second;
			tmp = i->first;
		}
	}
	cout << tmp;
	

}
