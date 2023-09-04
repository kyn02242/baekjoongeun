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
#define endl '\n'
#define INTMAX 2147483647
#define MAX 9223372036854775807

using namespace std;

int N, M, v1, v2;

vector<pair<int, int>> v[805];
int tmp[805];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void BFS(int Start)
{
    for (int i = 1; i <= N; i++)
    {
        tmp[i] = INTMAX;
    }
    tmp[Start] = 0;

    pq.push(make_pair(0, Start));

    while (!pq.empty())
    {
        int starting = pq.top().first;
        int ending = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[ending].size(); i++)
        {
            int End = v[ending][i].first;
            int Cost = v[ending][i].second;
            if (starting + Cost < tmp[End])
            {
                tmp[End] = starting + Cost;
                pq.push(make_pair(tmp[End], End));
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        v[tmp1].push_back(make_pair(tmp2, tmp3));
        v[tmp2].push_back(make_pair(tmp1, tmp3));
    }

    cin >> v1 >> v2;

    long long v1to1, v1tov2, v1toN, v2to1, v2toN;

    BFS(v1);
    v1to1 = tmp[1];
    v1tov2 = tmp[v2];
    v1toN = tmp[N];
    BFS(v2);
    v2to1 = tmp[1];
    v2toN = tmp[N];

    long long ans1 = v1to1 + v1tov2 + v2toN;
    long long ans2 = v2to1 + v1tov2 + v1toN;
    long long ans = ans1 < ans2 ? ans1 : ans2;

    if (ans >= INTMAX)
        ans = -1;

    printf("%lld", ans);

    return 0;
}