#include <vector>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int m;

int BFS(vector<vector<int>> &maps)
{
    q.push({0, 0});
    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ddx = x + dx[i];
            int ddy = y + dy[i];

            if (ddx == m - 1 && ddy == n - 1)
            { // 도착 지점
                maps[ddy][ddx] = maps[y][x] + 1;
                return maps[ddy][ddx];
            }
            if (ddx >= 0 && ddx < m && ddy >= 0 && ddy < n && maps[ddy][ddx] == 1)
            {
                q.push({ddy, ddx});
                maps[ddy][ddx] = maps[y][x] + 1;
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    n = maps.size();    // 세로
    m = maps[0].size(); // 가로
    answer = BFS(maps);
    return answer;
}