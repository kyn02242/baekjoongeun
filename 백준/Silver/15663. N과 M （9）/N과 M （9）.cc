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

using namespace std;

int n, m;

vector<int> v(10);
vector<int> tmpv(10);
bool visited[10];

void DFS(int x, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << tmpv[i]<<" ";
		}
		cout << endl;
		return;
	}

	int last = -1;

	for (int i = 0; i < n; i++)
	{
		if (v[i] != last&&!visited[i])//중복되는 수열 제거 조건
		{
			tmpv[cnt] = v[i];
			last = tmpv[cnt];
			visited[i] = true;
			DFS(i, cnt + 1);
			visited[i] = false;
		}
	}
	return;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin>>v[i];
	}

	sort(v.begin(), v.begin()+n);

	DFS(0, 0);

	return 0;
}