#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <sstream>
#include <memory>
#include <deque>
#include <iostream>

using namespace std;

int N;

vector<int> v[100001];
bool visited[100001];
int root[100001];

void DFS(int n) {
    visited[n] = true;
    for (int i = 0; i < v[n].size(); i++) {
        if (!visited[v[n][i]]) {
            root[v[n][i]] = n;
            DFS(v[n][i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N-1; i++) {
        int tmp1, tmp2;
        cin >> tmp1>>tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }

    visited[1] = true;

    DFS(1);

    for (int i = 2; i < N + 1; i++) {
        cout << root[i] << '\n';
    }

    return 0;
}
