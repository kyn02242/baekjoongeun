#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int n, m;

vector<vector<int>> v(1001, vector<int>(1001));

queue<pair<int, int>> q;

int xs[] = {1, 0, -1, 0};
int ys[] = {0, 1, 0, -1};

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
                if (v[dy][dx] == 0)
                {
                    v[dy][dx] = v[y][x] + 1;
                    q.push(make_pair(dy, dx));
                }
            }
        }
    }
}

int main()
{

    int startx;
    int starty;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 0)
            {
                v[i][j] = -1;
            }
            if (v[i][j] == 1)
            {
                v[i][j] = 0;
            }
            if (v[i][j] == 2)
            {
                q.push(make_pair(i, j));
                startx = j;
                starty = i;
                v[i][j] = 0;
            }
        }
    }

    BFS();

    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(v[i][j] == 0){
                v[i][j] = -2;
            }
            if(v[i][j]==-1){
                v[i][j] = 0;
            }
        }
    }
    v[starty][startx] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(v[i][j]==-2){
                v[i][j] = -1;
            }
            cout<<v[i][j]<<' ';
        }
        cout << endl;
    }
    return 0;
}