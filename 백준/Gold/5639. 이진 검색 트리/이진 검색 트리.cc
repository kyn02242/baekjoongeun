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
vector<int> v(1000000);

void CALCU(int root,int end){
	if(root>=end){
		return;
	}
	if(root==end-1){//루트만 남을경우
		cout<<v[root]<<endl;
		return;
	}
	int i = root+1;
	while(i<end){
		if(v[root]<v[i]){
			break;
		}
		i++;
	}
	CALCU(root+1,i);
	CALCU(i,end);
	cout<<v[root]<<endl;

}



int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int num;
	int i = 0;

	while(cin>>num){
		v[i++] = num;
	}
	CALCU(0,i);

	return 0;
}