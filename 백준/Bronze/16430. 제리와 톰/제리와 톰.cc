#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '₩n'
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int a, b;
	cin >> a >> b;
	if (a == b) {
		cout << 0;
	}
	else {
		cout << b - a << " " << b;
	}

}
