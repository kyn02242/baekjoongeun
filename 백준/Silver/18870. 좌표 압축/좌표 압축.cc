#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
// #include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> arr2(arr);
	sort(arr2.begin(),arr2.end());
	vector<int> arr3;
	map<int,int> mp;
	mp[arr2[0]] = 0;
	for(int i=1;i<arr2.size();i++){
		if(arr2[i-1]!=arr2[i]){
			mp[arr2[i]] = mp[arr2[i-1]];
			mp[arr2[i]]++;
		}
	}
	for(int i=0;i<arr.size();i++){
		cout << mp[arr[i]]<<" ";
	}
	
	

}