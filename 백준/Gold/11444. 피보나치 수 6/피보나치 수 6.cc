#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <sstream>
#include <memory>
#include <deque>
#include <stack>
#define endl '\n'
#define INTMAX 2147483647
#define LONGLONGMAX 9223372036854775807
using namespace std;


typedef vector<vector<long long>> matrix;
long long n;

matrix multiple (matrix& a, matrix& b)
{
	matrix c(2, vector<long long>(2));

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < 2; k++)
				c[i][j] += a[i][k] * b[k][j];
			c[i][j] %= 1000000007;
		}
	return c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n;

	matrix ans = {{1,0}, {0,1}};
	matrix a = {{1,1}, {1,0}};

	while (n > 0)
	{
		if (n % 2 == 1){
			ans = multiple(ans, a);
		}
		a = multiple(a, a);
		n /= 2;
	}
	
	cout << ans[0][1] << '\n';
}