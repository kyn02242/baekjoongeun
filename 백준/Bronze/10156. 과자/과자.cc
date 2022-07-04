#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (c <= a * b) {
		cout << (a * b) - c;
	}
	else {
		cout << "0";
	}
	
	return 0;
}