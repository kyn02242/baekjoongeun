#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int l(0);
	int sum(0);
	cin>>n;
	int flag(n);
	vector<int> arr(n);
	vector<int> brr(0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int r{n-1};
	while(0<r){
		if(flag == arr[r]){
			r--;
			flag--;
			continue;
		}
		while(arr[l]!=flag){
			l++;
		}
		
		brr.push_back(l+1);
		brr.push_back(r+1);

		reverse(arr.begin()+l,arr.begin()+r+1);
		sum++;

		l=0;
		r--;
		flag--;
		// for(int i=0;i<n;i++){
		// 	cout<<arr[i]<<" ";
		// }
		// cout<<"======"<<endl;
	}
	cout << sum << endl;
	for(int i=0;i<brr.size();i++){
		cout<< brr[i]<<" "<<brr[i+1]<<endl;
		i++;
	}

}