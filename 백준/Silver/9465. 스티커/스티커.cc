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

vector<vector<int>> v(2, vector<int>(100001));
vector<vector<int>> sum(2, vector<int>(100001));

int N, T;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<2;i++){
			for(int j=1;j<N+1;j++){
				cin>>v[i][j];
			}
		}
		sum[0][0] = 0;
		sum[1][0] = 0;
		sum[0][1] = v[0][1];
		sum[1][1] = v[1][1];

		for(int i=2;i<N+1;i++){
			sum[0][i] = max(sum[1][i-2],sum[1][i-1])+v[0][i];
			sum[1][i] = max(sum[0][i-2],sum[0][i-1])+v[1][i];
		}
		cout<<max(sum[0][N],sum[1][N])<<endl;
	}	
	return 0;
}