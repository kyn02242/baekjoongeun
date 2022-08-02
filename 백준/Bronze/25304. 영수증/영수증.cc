#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


bool compare(int a, int b)
{
	return a > b;
}

int main() {
	int a,sum=0;
    int n;
    cin>>a;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        sum+=tmp1*tmp2;
    }
    if(sum==a){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }


}
