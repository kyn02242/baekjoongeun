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
#include <stack>
#define endl '\n'
#define INTMAX 2147483647
#define LONGLONGMAX 9223372036854775807
#define MAX 100000

using namespace std;

int N, M, W;

struct edge {
	int Start, End, Time;
};

bool time_travel(vector<edge> edges) {
	vector<int> distance(N + 1, MAX);

	int start, end, time;
	distance[edges[0].Start] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < edges.size(); j++) {
			start = edges[j].Start;
			end = edges[j].End;
			time = edges[j].Time;
			if (distance[end] > distance[start] + time) {
				distance[end] = distance[start] + time;
			}
		}
	}
	for (int j = 0; j < edges.size(); j++) {
		start = edges[j].Start;
		end = edges[j].End;
		time = edges[j].Time;
		if (distance[end] > distance[start] + time) {
			return true;
		}
	}

	return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
    
    int TC;
	cin >> TC;

	int start, end, time;
	while (TC--) {
		cin >> N >> M >> W;

		vector<edge> edges;

		for (int i = 0; i < M; i++) {
			cin >> start >> end >> time;
			edges.push_back({ start,end,time });
			edges.push_back({ end,start,time });
		}
		for (int i = 0; i < W; i++) {
			cin >> start >> end >> time;
			edges.push_back({ start,end,-time });
		}
		if (time_travel(edges)){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}

	return 0;
}