#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int n, m;

vector<vector<char>> v(601, vector<char>(601));

queue<pair<int, int>> q;

int xs[] = {1, 0, -1, 0};
int ys[] = {0, 1, 0, -1};

int ans = 0;

void BFS()
{
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int dy = y + ys[i];
            int dx = x + xs[i];
            if (dx >= 0 && dy >= 0 && dx < m && dy < n)
            {
                if (v[dy][dx] == 'O' || v[dy][dx] == 'P')
                {
                    if (v[dy][dx] == 'P')
                    {
                        ans++;
                    }
                    v[dy][dx] = 'I';
                    q.push(make_pair(dy, dx));
                }
            }
        }
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'I')
            {
                q.push(make_pair(i, j));
            }
        }
    }

    BFS();
    if (ans == 0)
    {
        cout << "TT";
    }
    else
    {
        cout << ans;
    }

    return 0;
}