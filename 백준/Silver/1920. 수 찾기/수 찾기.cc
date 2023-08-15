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

vector<int> v(100000);
int tmp;
int N,M;

void search(int num){
	int left = 0;
	int right = N-1;
	
	while(left<=right){
		int mid =(left+right)/2;
		if(v[mid]==num){
			cout<<1<<endl;
			return;
		}
		else if(num>v[mid]){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
	cout<<0<<endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.begin()+N);
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>tmp;
		search(tmp);
	}
	



	return 0;
}