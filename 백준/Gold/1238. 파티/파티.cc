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

vector<vector<int>> v1(1001,vector<int>(1001,MAX));
vector<vector<int>> v2(1001,vector<int>(1001,MAX));
int N, M, X;
queue<pair<int,int>> q;

void BFS(int n){
	if(n==0){
	for(int i=1;i<=N;i++){
		if(v1[X][i]!=0){
			q.push(make_pair(X,i));
		}
	}
	while(!q.empty()){
		int start = q.front().first;
		int Newstart = q.front().second;
		q.pop();
		for(int i=1;i<=N;i++){
			if(v1[Newstart][i]!=MAX){
				if(v1[start][i]<=v1[start][Newstart]+v1[Newstart][i]){
					continue;
				}
				else{
					v1[start][i]=v1[start][Newstart]+v1[Newstart][i];
					q.push(make_pair(start,i));
				}
			}
		}
	}
	}
	else{
		for(int i=1;i<=N;i++){
		if(v2[X][i]!=0){
			q.push(make_pair(X,i));
		}
	}
	while(!q.empty()){
		int start = q.front().first;
		int Newstart = q.front().second;
		q.pop();
		for(int i=1;i<=N;i++){
			if(v2[Newstart][i]!=MAX){
				if(v2[start][i]<=v2[start][Newstart]+v2[Newstart][i]){
					continue;
				}
				else{
					v2[start][i]=v2[start][Newstart]+v2[Newstart][i];
					q.push(make_pair(start,i));
				}
			}
		}
	}
	}
	// for(int i=1;i<=N;i++){
	// 	for(int j=1;j<=N;j++){
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
}




int main()
{
    ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
    
    cin>>N>>M>>X;
	int start,end,time;
	for(int i=0;i<M;i++){
		cin>>start>>end>>time;
		v1[start][end] = time;
		v2[end][start] = time;
	}
	
	BFS(0);
	BFS(1);

	int ans = 0;

	for(int i=1;i<=N;i++){
		if(i==X){
			v1[X][i] = 0;
			v2[X][i] = 0;
		}
		ans = max(ans,v1[X][i]+v2[X][i]);
	}
	// for(int i=1;i<=N;i++){
	// 	cout<<v1[X][i]<<" ";
	// }
	// cout<<endl;
	cout<<ans<<endl;

	return 0;
}