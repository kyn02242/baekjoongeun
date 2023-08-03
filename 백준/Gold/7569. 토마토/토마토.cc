#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;
int m, n, h;

vector<vector<vector<int>>> v(101, vector<vector<int>>(101, vector<int>(101)));

struct spot
{
    int z;
    int y;
    int x;
};

int xarr[6] = {1, 0, -1, 0, 0, 0};
int yarr[6] = {0, 1, 0, -1, 0, 0};
int zarr[6] = {0, 0, 0, 0, 1, -1};

queue<spot> q;

void BFS()
{
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;

        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int dx = x + xarr[i];
            int dy = y + yarr[i];
            int dz = z + zarr[i];

            if (dz >= 0 && dx >= 0 && dy >= 0 && dy < n && dx < m && dz < h)
            {
                if (v[dz][dy][dx] != -1)
                {
                    if (v[dz][dy][dx] == 0)
                    {
                        v[dz][dy][dx] = v[z][y][x] + 1;
                        spot tmp;
                        tmp.z = dz;
                        tmp.y = dy;
                        tmp.x = dx;
                        q.push(tmp);
                    }
                    else
                    {
                        if (v[dz][dy][dx] > v[z][y][x] + 1)
                        {
                            v[dz][dy][dx] = v[z][y][x] + 1;
                        }
                    }
                }
            }
        }
        // for (int i = 0; i < h; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         for (int k = 0; k < m; k++)
        //         {
        //             if(v[i][j][k]>=0){
        //                 cout<<" ";
        //             }
        //             cout << v[i][j][k] << " ";
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
}

int main()
{
    int cnt = 0;

    cin >> m >> n >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> v[i][j][k];
                if (v[i][j][k] == 0)
                {
                    cnt++;
                }
                if (v[i][j][k] == 1)
                {
                    spot rotten;
                    rotten.z = i;
                    rotten.y = j;
                    rotten.x = k;
                    q.push(rotten);
                }
            }
        }
    }

    if (cnt == 0)
    {
        cout << 0;
        return 0;
    }

    BFS();

    int max = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (v[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
                if (v[i][j][k] > max)
                {
                    max = v[i][j][k];
                }
            }
        }
    }
    cout<<max-1;

    return 0;
}