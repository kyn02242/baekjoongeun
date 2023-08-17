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

int N, M;

vector<vector<long long>> v(1001, vector<long long>(1001, MAX));
queue<pair<int, long long>> q;

void CALCU(int st, int ed)
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
		long long cost = q.front().second;
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
	// cout << v[st][ed] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int start, end;
		long long cost;
		cin >> start >> end >> cost;
		if (v[start - 1][end - 1] > cost)
		{
			v[start - 1][end - 1] = cost;
		}
		if (start == end)
		{
			cost = 0;
		}
	}
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<N;j++){
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i != j)
			{
				CALCU(i, j);
				break;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				cout << 0 << " ";
				continue;
			}
			if (v[i][j] == MAX)
			{
				cout << 0 << " ";
				continue;
			}
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<N;j++){
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return 0;
}