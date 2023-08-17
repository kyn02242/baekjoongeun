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
#define endl '\n'
#define MAX 2000000000
#define MIN -2000000000

using namespace std;

int main(){

    int sec = 0;
    int pos1;
    int pos2;

    cin>>pos1>>pos2;

    if(pos2<=pos1){
        cout<<pos1-pos2<<endl;
        return 0;
    }

    queue<int> q;
    vector<int> v(1000000,MAX);

	v[pos1] = 0;
    q.emplace(pos1);

    while(!q.empty()){

        // for(int i = 1;i<10;i++){
        //     cout<< v[i] << " ";
        // }
        // cout<<endl;

        int x = q.front();

        if(x==pos2){
            //cout<<"x : "<<x<<endl<<"v["<<x<<"] : "<<v[x]<<endl;
            cout<<v[x]<<endl;
            return 0;
        }
        if(x>2*pos2){
            q.pop();
            continue;
        }

        //cout<<"x : "<<x<<endl<<"v["<<x<<"] : "<<v[x]<<endl;

        if(v[x+1]>v[x]+1){
            v[x+1] = v[x]+1;
            if(x+1!=pos1){
                q.push(x+1);
            }
        }
        if(v[x*2]>v[x]){
            v[x*2]=min(v[x*2],v[x]);
            if(2*x!=pos1){
                q.push(2*x);
            }
        }
        if(x-1>0&&v[x-1]>v[x]+1){
            v[x-1]=v[x]+1;
            if(x-1!=pos1){
                q.push(x-1);
            }
        }
        q.pop();
    }


    return 0;
}