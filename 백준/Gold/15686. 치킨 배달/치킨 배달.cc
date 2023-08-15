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
#define MAX 987654321

using namespace std;

vector<vector<int>> v(51, vector<int>(51));
vector<pair<int,int>> house;
vector<pair<int,int>> chic;
bool select_list[13] = {false};
vector<pair<int,int>> pick;

int N,M;
int ans = MAX;

int wholechicken(){
	int sum = 0;
	for(int i=0;i<house.size();i++){
		int min = MAX;
		for(int j=0;j<pick.size();j++){
			if(abs(house[i].first-pick[j].first)+abs(house[i].second-pick[j].second)<min){
				min = abs(house[i].first-pick[j].first)+abs(house[i].second-pick[j].second);
			}
		}
		sum+=min;
	}
	return sum;
}

void select(int n, int cnt)
{
    if (cnt == M)
    {
        ans = min(ans, wholechicken());
        return;
    }
 
    for (int i = n; i < chic.size(); i++)
    {
        if(select_list[i] == true) continue;
        select_list[i] = true;
		pick.push_back(make_pair(chic[i].first,chic[i].second));
        select(i, cnt + 1);
        select_list[i] = false;
		pick.pop_back();
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N>>M;

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++){
			cin>>v[i][j];
			if(v[i][j]==1){
				house.push_back(make_pair(i,j));
			}
			if(v[i][j]==2){
				chic.push_back(make_pair(i,j));
			}
		}
	}
	select(0,0);

	cout<<ans;
	


	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<N;j++){
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return 0;
}