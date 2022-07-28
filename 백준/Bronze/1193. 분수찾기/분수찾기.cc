#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


bool compare(int a, int b)
{
	return a > b;
}

int main() {
	int n;
	cin >> n;

	int i = 1;
	while (n > i) {
		n -= i;
		i++;
	}

	if (i % 2 == 1)
		cout << i + 1 - n << '/' << n << endl;
	else
		cout << n << '/' << i + 1 - n << endl;
}
