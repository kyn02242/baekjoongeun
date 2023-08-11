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

using namespace std;

int N;
vector<int> v(1001);
vector<int> save(1001);

int search(int x){
	if(x==0){
		save[x] = 1;
		return 1;
	}
	int max = 0;
	for(int i=0;i<x;i++){
		if(v[i]<v[x]){
			if(max<save[i]){
				max = save[i];
			}
		}
	}
	save[x] = max+1;
	return save[x];
}

int main()
{
	cin >> N;
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		cin>>v[i];
		int tmp = search(i);
		if(max<tmp){
			max = tmp;
		}
	}

	cout<<max;


	return 0;
}