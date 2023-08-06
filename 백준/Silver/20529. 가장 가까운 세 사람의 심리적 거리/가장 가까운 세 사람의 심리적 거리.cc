#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <sstream>
#include <memory>
#include <deque>

using namespace std;

vector<string> v(100001);

int count(int a,int b,int c){
    int ans = 0;
    for(int i=0;i<4;i++){
        if(v[a][i]!=v[b][i]){
            ans++;
        }
        if(v[c][i]!=v[b][i]){
            ans++;
        }
        if(v[a][i]!=v[c][i]){
            ans++;
        }
    }
    return ans;
}

int main()
{
    int T;
    int cnt=0;
    int N;
    int ans;
    cin>>T;
    for(int i=0;i<T;i++){
        ans=987654321;
        cin>>N;
        for(int j=0;j<N;j++){
            cin>>v[j];
        }
        if(N>32){
            cout<<0<<endl;
            continue;
        }
        for(int j=0;j<N;j++){
            for(int k=j+1;k<N;k++){
                for(int l=k+1;l<N;l++){
                    ans = min(ans,count(j,k,l));
                }                
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}