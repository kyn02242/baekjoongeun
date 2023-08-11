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

using namespace std;

vector<vector<int>> v(1025, vector<int>(1025));

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			if (i == j && i == 0)
			{
				v[i][j] = tmp;
				continue;
			}
			if (i == 0)
			{
				v[i][j] = v[i][j - 1] + tmp;
				continue;
			}
			if (j == 0)
			{
				v[i][j] = v[i - 1][j] + tmp;
				continue;
			}
			v[i][j] = tmp + v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
		}
	}
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<N;j++){
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }

	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		x1 -= 1;
		x2 -= 1;
		y1 -= 1;
		y2 -= 1;
		if (x1 == 0 && y1 == 0)
		{
			cout << v[x2][y2] << '\n';
			continue;
		}
		if (x1 == 0)
		{
			cout << v[x2][y2] - v[x2][y1 - 1] << '\n';
			continue;
		}
		if (y1 == 0)
		{
			cout << v[x2][y2] - v[x1 - 1][y2] << '\n';
			continue;
		}
		cout << v[x2][y2] - v[x1 - 1][y2] - v[x2][y1 - 1] + v[x1 - 1][y1 - 1] << '\n';
	}
	return 0;
}