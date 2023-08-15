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
#define MAX 2000000000

using namespace std;

int N, M;
int st, ed;
vector<vector<int>> v(1000, vector<int>(1000, MAX));
queue<pair<int, int>> q;

void CALCU()
{
	for (int i = 0; i < N; i++)
	{
		if (v[st][i] != MAX)
		{
			q.push(make_pair(i, v[st][i]));
		}
	}
	while (!q.empty())
	{
		int end = q.front().first;
		int cost = q.front().second;
		q.pop();
		for (int i = 0; i < N; i++)
		{
			if (v[end][i] != MAX)
			{
				if (v[st][i] == MAX || v[st][i] > cost + v[end][i])
				{
					v[st][i] = cost + v[end][i];
					q.push(make_pair(i, cost + v[end][i]));
				}
			}
		}
	}
	cout << v[st][ed] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		if (v[start - 1][end - 1] > cost)
		{
			v[start - 1][end - 1] = cost;
		}
	}
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<N;j++){
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cin >> st >> ed;
	st--;
	ed--;
	CALCU();

	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<N;j++){
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return 0;
}