#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <sstream>
#include <memory>
#include <deque>
#include <set>
#define endl '\n'
#define MAX 2000000000
#define MIN -2000000000

using namespace std;

int N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	vector<vector<int>> v(101, vector<int>(100001));
	vector<int> Wei(101);
	vector<int> Val(101);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> Wei[i] >> Val[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{

			if (j - Wei[i] >= 0)
				v[i][j] = max(v[i - 1][j], v[i - 1][j - Wei[i]] + Val[i]);
			else
				v[i][j] = v[i - 1][j];
		}
	}
	cout<<v[N][K]<<endl;

	return 0;
}