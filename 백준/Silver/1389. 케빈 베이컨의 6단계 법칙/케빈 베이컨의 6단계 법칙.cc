#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <deque>
#include <numeric>
#define endl '\n'
#define MAX INT32_MAX

using namespace std;

int n;
vector<vector<int>> v;

int bfs(int start) {
    vector<int> dist_arr(n + 1, 0);
    vector<bool> visit(n + 1, 0);
    queue<pair<int, int>> q;

    q.push(make_pair(start, 0));
    visit[start] = true;

    while(!q.empty()) {
        int before = q.front().first;
        int beforeDistance = q.front().second;
        q.pop();
        
        for(auto i : v[before]) {
            if (!visit[i]) {
                q.push({i, beforeDistance + 1});
                visit[i] = true;
                dist_arr[i] = beforeDistance + 1;
            }
        }
    }
    return accumulate(dist_arr.begin() + 1, dist_arr.end(), 0);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, h1, h2;
    cin >> n >> m;

    v.resize(n + 1);

    for(int i = 0; i < m; i++) {
        cin >> h1 >> h2;
        v[h1].push_back(h2);
        v[h2].push_back(h1);
    }

    int answer = 0;
    int maxNum = MAX;
    int tmp;
    for(int i = 1; i <= n; i++) {
        tmp = bfs(i);
        if (maxNum > tmp) {
            maxNum = tmp;
            answer = i;
        }
    }
    cout << answer;
}