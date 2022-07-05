#include<bits/stdc++.h>
using namespace std;


int main(){
	
	string arr1[100];
	string arr2[100];
	int n;
	int tmp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr1[i];
		arr2[i] = arr1[i];
		reverse(arr2[i].begin(),arr2[i].end());
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr1[i]==arr2[j]){
				tmp = i;
				break;
			}
		}
	}
	cout<< arr1[tmp].length() <<" "<<arr1[tmp][arr1[tmp].length()/2]<<endl;

	

	return 0;
}