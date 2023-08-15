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

using namespace std;

vector<vector<int>> v(27, vector<int>(2));
int N;

void DFS_front(int num){
	if(num == -1){
		return;
	}
	cout<<char(num+'A');
	DFS_front(v[num][0]);
	DFS_front(v[num][1]);
}
void DFS_mid(int num){
	if(num == -1){
		return ;
	}
	DFS_mid(v[num][0]);
	cout<<char(num+'A');
	DFS_mid(v[num][1]);
}
void DFS_back(int num){
	if(num == -1){
		return ;
	}
	DFS_back(v[num][0]);
	DFS_back(v[num][1]);
	cout<<char(num+'A');
}


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;
	char Root, left, right;
	for (int i = 0; i < N; i++)
	{
		cin >> Root >> left >> right;
		if (left != '.')
		{
			v[Root - 'A'][0] = left - 'A';
		}
		if(left == '.'){
			v[Root - 'A'][0] = -1;
		}
		if (right != '.')
		{
			v[Root - 'A'][1] = right - 'A';
		}
		if(right == '.'){
			v[Root - 'A'][1] = -1;
		}
	}
	DFS_front(0);
	cout<<endl;
	DFS_mid(0);
	cout<<endl;
	DFS_back(0);


	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<N;j++){
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return 0;
}