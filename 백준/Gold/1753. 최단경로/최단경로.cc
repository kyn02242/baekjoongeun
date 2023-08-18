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
#define LONGLONGMAX 9223372036854775807

using namespace std;

int AnswerArr[20001];
vector<pair<int,int>> IntPairVector[300001];//<Cost,NodeNum>

void Dijkstra(int StartNodeNum){
	AnswerArr[StartNodeNum] = 0;
	priority_queue<pair<int,int>> IntPairPriorityQueue;
	IntPairPriorityQueue.push(make_pair(0,StartNodeNum));
	while(!IntPairPriorityQueue.empty()){
		int NowWatchingNode = IntPairPriorityQueue.top().second;
		int DistanceFromStartNode = -IntPairPriorityQueue.top().first;//To Make Cost Ascending
		IntPairPriorityQueue.pop();

		if(AnswerArr[NowWatchingNode]<DistanceFromStartNode)continue;

		for(int i=0;i<IntPairVector[NowWatchingNode].size();i++){
			int NextNode = IntPairVector[NowWatchingNode][i].second;

			int DistanceToNextNode = DistanceFromStartNode + IntPairVector[NowWatchingNode][i].first;
			if(AnswerArr[NextNode]>DistanceToNextNode){
				AnswerArr[NextNode]=DistanceToNextNode;
				IntPairPriorityQueue.push(make_pair(-DistanceToNextNode,NextNode));
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int Node,NodeStart,Edge;
	cin>>Node>>Edge>>NodeStart;

	for(int i=1;i<=Node;i++){
		AnswerArr[i] = INTMAX;
	}

	for(int i=0;i<Edge;i++){
		int starttmp,endtmp,costtmp;
		cin>>starttmp>>endtmp>>costtmp;
		IntPairVector[starttmp].push_back(make_pair(costtmp,endtmp));
	}

	Dijkstra(NodeStart);

	for(int i=1;i<=Node;i++){
		if(AnswerArr[i]==INTMAX){
			cout<<"INF"<<endl;
		}
		else{
			cout<<AnswerArr[i]<<endl;
		}
	}



	return 0;
}