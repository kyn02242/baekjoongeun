#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
// #include<bits/stdc++.h>

using namespace std;

int main(){
	
	vector<int> a(3);
	for(int i = 0;i<a.size();i++){
		cin>>a[i];
	}
	std::sort(a.begin(),a.end());
	//std::reverse(a.begin(),a.end());
	cout<<a[1];

}