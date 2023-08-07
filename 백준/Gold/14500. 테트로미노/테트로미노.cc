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

int N, M;
vector<vector<int>> v(500, vector<int>(500));
vector<vector<bool>> visited(500, vector<bool>(500));
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

int ans;


void DFS(int x, int y, int depth, int sum)
{
    if (depth == 3)
    {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int dx = dirx[i] + x;
        int dy = diry[i] + y;
        if (dx >= 0 && dy >= 0 && dx < N && dy < M)
        {
            if (visited[dx][dy] == false)
            {
                visited[dx][dy] = true;
                DFS(dx, dy, depth + 1, sum + v[dx][dy]);
                visited[dx][dy] = false;
            }
        }
    }
}

void shape1(int r, int c)
{
    int sum = 0;
    sum = v[r][c] + v[r][c + 1] + v[r][c + 2] + v[r - 1][c + 1];
    ans = max(ans, sum);
}

void shape2(int r, int c)
{
    int sum = 0;
    sum = v[r][c] + v[r][c + 1] + v[r][c + 2] + v[r + 1][c + 1];
    ans = max(ans, sum);
}

void shape3(int r, int c)
{
    int sum = 0;
    sum = v[r][c] + v[r + 1][c] + v[r + 2][c] + v[r + 1][c + 1];
    ans = max(ans, sum);
}

void shape4(int r, int c)
{
    int sum = 0;
    sum = v[r][c] + v[r - 1][c + 1] + v[r][c + 1] + v[r + 1][c + 1];
    ans = max(ans, sum);
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = true;
            DFS(i, j, 0, v[i][j]);
            visited[i][j] = false;
            if (i >= 1 && j + 2 < M)
                shape1(i, j);
            if (j + 2 < M && i + 1 < N)
                shape2(i, j);
            if (i + 2 < N && j + 1 < M)
                shape3(i, j);
            if (i + 1 < N && i >= 1 && j + 1 < M)
                shape4(i, j);
        }
    }
    cout<<ans<<endl;

    return 0;
}