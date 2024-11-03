#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#define endl '\n'

using namespace std;

int GCD(int a, int b) {
	int r = a % b;
	if (r == 0)
		return b;
	else
		return GCD(b, r);
}

int main() {
	int n;
	int gcd = 0;
	int count = 0;

	cin >> n;
    vector<int> tree(n);
    vector<int> diff(n);


	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}

	for (int i = 0; i < n - 1; i++) {
		diff[i] = tree[i + 1] - tree[i];
	}

	gcd = diff[0];
	for (int i = 1; i < n - 1; i++) {
		gcd = GCD(gcd, diff[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		count += (diff[i] / gcd) - 1;	
	}

	cout << count;

	return 0;
}