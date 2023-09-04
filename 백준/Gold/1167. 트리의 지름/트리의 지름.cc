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
#define MAX 9223372036854775807

using namespace std;

int answer = 0;
int flag = 1;
vector<pair<int, int>> node[100001];

void DFS(int Start, int End, int Len) {
    if(Len > answer) {
        answer = Len;
        flag = Start;
    }
    for(int i=0; i<node[Start].size(); i++)
        if(node[Start][i].first != End) DFS(node[Start][i].first, Start, Len+node[Start][i].second);
}

int main() {
    ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

    int N, a, b, c;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> a;
        while(1) {
            cin >> b;
            if(b == -1) break;
            cin >> c;
            node[a].push_back(make_pair(b, c));
        }
    }

    DFS(1, 0, 0);
    answer = 0;
    DFS(flag, 0, 0);
    cout << answer;
}