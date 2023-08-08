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

int N;
int ans = 0;
vector<vector<int>> v(16, vector<int>(16));
queue<pair<int, pair<int, int>>> q;

void BFS()
{
	int stance = 0; // 0 = 가로, 1 = 세로, 2 = 대각선
	int y = 0;		// 도착 지점의 y좌표
	int x = 1;		// 도착 지점의 x좌표

	q.push(make_pair(stance, make_pair(x, y)));
	while (!q.empty())
	{
		int xx = q.front().second.first;
		int yy = q.front().second.second;
		int sstance = q.front().first;
		q.pop();

		// cout<<xx<<" "<<yy<<" "<<sstance<<" "<<endl;

		if (xx == yy && xx == N - 1)
		{ // 잘 도착한 경우
			ans++;
			continue;
		}

		if (sstance == 0)
		{ // 가로일 경우

			if (xx + 1 < N && v[yy][xx + 1] != 1)
			{												 // 가로로 갈 수 있으면
				q.push(make_pair(0, make_pair(xx + 1, yy))); // 가로 간다
			}
			if (xx + 1 < N && v[yy][xx + 1] != 1 && yy + 1 < N && v[yy + 1][xx] != 1 && v[yy + 1][xx + 1] != 1)
			{													 // 셋 다 갈 수 있으면
				q.push(make_pair(2, make_pair(xx + 1, yy + 1))); // 대각선 간다
			}
		}
		else if (sstance == 1)
		{ // 세로일 경우
			if (yy + 1 < N && v[yy + 1][xx] != 1)
			{												 // 세로로 갈 수 있으면
				q.push(make_pair(1, make_pair(xx, yy + 1))); // 세로 간다
			}
			if (xx + 1 < N && v[yy][xx + 1] != 1 && yy + 1 < N && v[yy + 1][xx] != 1 && v[yy + 1][xx + 1] != 1)
			{													 // 셋 다 갈 수 있으면
				q.push(make_pair(2, make_pair(xx + 1, yy + 1))); // 대각선 간다
			}
		}
		else
		{ // 대각선일 경우
			if (xx + 1 < N && v[yy][xx + 1] != 1)
			{												 // 가로로 갈 수 있으면
				q.push(make_pair(0, make_pair(xx + 1, yy))); // 가로 간다
			}
			if (yy + 1 < N && v[yy + 1][xx] != 1)
			{												 // 세로로 갈 수 있으면
				q.push(make_pair(1, make_pair(xx, yy + 1))); // 세로 간다
			}
			if (xx + 1 < N && v[yy][xx + 1] != 1 && yy + 1 < N && v[yy + 1][xx] != 1 && v[yy + 1][xx + 1] != 1)
			{													 // 셋 다 갈 수 있으면
				q.push(make_pair(2, make_pair(xx + 1, yy + 1))); // 대각선 간다
			}
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> v[i][j];
		}
	}

	BFS();

	cout << ans << endl;

	return 0;
}