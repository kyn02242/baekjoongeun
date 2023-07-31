#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;
int m, n;

vector<vector<int>> v(1001, vector<int>(1001));

int xarr[4] = {1, 0, -1, 0};
int yarr[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

void BFS()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int dx = x + xarr[i];
            int dy = y + yarr[i];

            if (dx >= 0 && dy >= 0 && dy < m && dx < n)
            {
                if (v[dx][dy] == 0)
                {
                    v[dx][dy] = v[x][y] + 1;
                    q.push(make_pair(dx, dy));
                }
            }
        }
    }
}

int main()
{
    int max=0;

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 1)
            {
                q.push(make_pair(i, j));
            }
        }
    }

    BFS();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(v[i][j]==0){
                cout<<-1<<endl;
                //cout<<i<<" "<<j;
                return 0;
            }
            if(v[i][j]>max){
                max = v[i][j];
            }

            //cout<<v[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<max-1;

    return 0;
}