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

vector<vector<int>> v(501,vector<int>(501));
int N;
int ans = 0;

void CALCU(){
    for(int i=1;i<N;i++){
        for(int j=0;j<=i;j++){
            //왼
            if(j==0){
                v[i][j]+=v[i-1][j];
            }
            //오
            else if(j==i){
                v[i][j]+=v[i-1][j-1];
            }
            //중간
            else{
                v[i][j] += max(v[i-1][j],v[i-1][j-1]);
            }
        }
    }
    for(int i=0;i<N;i++){
        
        if(v[N-1][i]>ans){
            ans = v[N-1][i];
        }
    }
    cout<<ans<<endl;
}

int main()
{
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            cin>>v[i][j];
        }
    }

    CALCU();

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}