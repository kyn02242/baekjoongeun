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

int N;
vector<pair<int, int>> v[10001];
bool visited[10001];
int ans = 0;
int dot = 0;

void longest(int start, int cost)
{
	if (visited[start])
	{
		return;
	}
	visited[start] = true;
	if (ans < cost)
	{
		ans = cost;
		dot = start;
	}

	for (int i = 0; i < v[start].size(); i++)
	{
		longest(v[start][i].first, cost + v[start][i].second);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int tmp1, tmp2, tmp3;
		cin >> tmp1 >> tmp2 >> tmp3;
		v[tmp1].push_back(make_pair(tmp2, tmp3));
		v[tmp2].push_back(make_pair(tmp1, tmp3));
	}
	longest(1, 0);
	memset(visited, false, sizeof(visited));

	longest(dot, 0);

	cout << ans;

	return 0;
}