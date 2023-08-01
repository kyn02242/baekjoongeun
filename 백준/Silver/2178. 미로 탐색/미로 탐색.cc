#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int n, m;

vector<vector<int>> v(101, vector<int>(101));

vector<char> vtmp(101);


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
                if (v[dy][dx] == 1)
                {
                    v[dy][dx] = v[y][x]+1;
                    q.push(make_pair(dy, dx));
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j= 0;j<m;j++){
        //         cout<<v[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
    }
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>vtmp[j];
            v[i][j] = (int)vtmp[j]-'0';
            if(i==0&&j==0){
                q.push(make_pair(i,j));
            }
        }
    }

    BFS();

    cout<<v[n-1][m-1];

    return 0;
}