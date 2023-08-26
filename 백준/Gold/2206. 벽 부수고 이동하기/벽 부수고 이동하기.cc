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

int N, M;

struct spot
{
	int x;
	int y;
	bool breaking;
	int dist;
};
vector<vector<int>> v(1001, vector<int>(1001));
queue<spot> q;
bool visited[1001][1001][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS()
{
	visited[0][0][0] = true;
	visited[0][0][1] = true;
	spot start = {0, 0, 0, 1};
	q.push(start);
	while (!q.empty())
	{
		int X = q.front().x;
		int Y = q.front().y;
		bool Breaking = q.front().breaking;
		int Dist = q.front().dist;
		q.pop();
		if (X == N - 1 && Y == M - 1)
		{
			return Dist;
		}
		for (int i = 0; i < 4; i++)
		{
			int dX = X + dx[i];
			int dY = Y + dy[i];
			if (dX >= 0 && dX <= N - 1 && dY >= 0 && dY <= M - 1 && visited[dX][dY][Breaking] == false)
			{
				if (v[dX][dY] == 0 && Breaking == false)
				{ // 벽 없는데 아직 안부숨
					visited[dX][dY][Breaking] = true;
					spot NewSpot = {dX, dY, false, Dist + 1};
					q.push(NewSpot);
				}
				else if (v[dX][dY] == 0 && Breaking == true)
				{ // 벽 없는데 부숨
					visited[dX][dY][Breaking] = true;
					spot NewSpot = {dX, dY, true, Dist + 1};
					q.push(NewSpot);
				}
				else if (v[dX][dY] == 1 && Breaking == false)
				{ // 벽 있는데 아직 안부숨
					visited[dX][dY][Breaking] = true;
					spot NewSpot = {dX, dY, true, Dist + 1};
					q.push(NewSpot);
				}
				else if (v[dX][dY] == 1 && Breaking == true)
				{ // 벽 있는데 부숨
					continue;
				}
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;

	char tmp;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tmp;
			v[i][j] = tmp - '0';
		}
	}
	cout << BFS() << endl;

	return 0;
}