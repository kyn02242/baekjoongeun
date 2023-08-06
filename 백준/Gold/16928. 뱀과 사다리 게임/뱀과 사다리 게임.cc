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
vector<int> v(102);
vector<int> visited(101);
queue<pair<int,int>> q;

void BFS(int start,int c){
    q.push(make_pair(start,c));
    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for(int i=1;i<=6;i++){
            int new_x = x+i;
            if(new_x == 100){
                cout<<cnt+1;
                return;
            }
            else if(new_x<100){
                if(v[new_x]!=0){
                    new_x = v[new_x];
                }
                if(visited[new_x]==0){
                    q.push(make_pair(new_x,cnt+1));
                    visited[new_x] = 1;
                }
            }
        }
        
    }
}
 
int main(){
    int n, m, t1, t2;
    
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> t1 >> t2; 
        v[t1] = t2; // 사다리 저장
    }
    for (int i = 0; i < m;i++){
        cin >> t1 >> t2;
        v[t1] = t2; // 뱀 저장
    }
    BFS(1, 0);
    return 0;
}