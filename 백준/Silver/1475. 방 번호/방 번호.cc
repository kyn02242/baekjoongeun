#include <bits/stdc++.h>
using namespace std;

int arr[10];
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	int max = 0;
	cin>>n;
	while(n>0){
		m=n%10;
		if(m==9){
			m=6;
		}
		arr[m]++;
		n/=10;
	}
	if(arr[6]%2==0){
		arr[6] /=2;
	}
	else{
		arr[6]/=2;
		arr[6]++;
	}
	for(int i = 0;i<10;i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	cout<<max;
}