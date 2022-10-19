#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==1){
        return 0;
    }
    else{
        for(int i=2;i<n;i++){
            if(n%i==0){
                cout<<i<<endl;
                n/=i;
                i--;
            }
        }
        cout<<n<<endl;
    }
    return 0;
}