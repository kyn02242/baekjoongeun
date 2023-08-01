#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int n;

vector<vector<int>> v(101, vector<int>(101));

queue<pair<int, int>> q;

void BFS()
{
    while (!q.empty())
    {
        int start = q.front().first;
        int end = q.front().second;

        q.pop();

        //cout << start << " , " << end << endl;

        for (int i = 0; i < n; i++)
        {
            if (v[end][i] == 1)
            {
                if(v[start][i]!=1){
                    v[start][i] = 1;
                    q.push(make_pair(start,i));
                }
                else{
                    continue;
                }
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << v[i][j];
        //     }
        //     cout << endl;
        // }
    }
}

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
            if(v[i][j]==1){
                q.push(make_pair(i,j));
            }
        }
    }

    BFS();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j]<<' ';
        }
        cout << endl;
    }

    return 0;
}