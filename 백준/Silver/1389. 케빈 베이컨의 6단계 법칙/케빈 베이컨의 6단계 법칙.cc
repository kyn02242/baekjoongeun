#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <memory.h>

using namespace std;

int n, m;
vector<int> v[101];
int visited[101] = {0};

int BFS(int start, int end)
{
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0)); // start to q.front.first distance
    visited[start] = 1;

    while (!q.empty())
    {
        int tmp_start = q.front().first;
        int distance = q.front().second;
        q.pop();

        // cout<<start<<",,,"<<end<<endl;
        // cout<<start<<','<<end<<','<<distance<<endl<<endl;
        if (tmp_start == end)
        {
            //cout << start << ',' << end << ',' << distance << endl;
            return distance;
        }

        for (int i = 0; i < v[tmp_start].size(); i++)
        {
            // cout<<tmp_start<<",,,"<<distance<<endl;
            if (v[tmp_start][i] != 0)
            {
                // cout<<tmp_start<<",,"<<distance<<endl;
                if (visited[v[tmp_start][i]] == 0)
                {
                    // cout<<start<<",,"<<end<<endl;
                    // cout<<tmp_start<<','<<distance<<endl;
                    // cout<<endl;
                    q.push(make_pair(v[tmp_start][i], distance + 1));
                    visited[v[tmp_start][i]] = 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    int a, b;
    int min = 10000000;
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            memset(visited, 0, 101);
            if (i == j)
                continue;
            sum += BFS(i, j);
        }
        if (min > sum)
        {
            min = sum;
            ans = i;
        }
    }

    cout << ans;

    return 0;
}
