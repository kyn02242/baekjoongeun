#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int BFS(int x,int y,int n,int m,vector<string> &map){
    int sum = 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int realx = q.front().first;
        int realy = q.front().second;
        //cout<<realx<<" "<<realy<<endl;
        q.pop();
        if(map[realx][realy]=='X'){
            continue;
        }
        sum = sum+ map[realx][realy]-'0';
        //cout<<"int map[realx][realy] - '0' : "<<map[realx][realy]-'0'<<endl;
        //cout<<realx<<" : "<<realy<<endl;
        map[realx][realy] = 'X';
        for(int i=0;i<4;i++){
            int ddx = realx+dx[i];
            int ddy = realy+dy[i];
            if(ddx>=0&&ddx<n&&ddy>=0&&ddy<m){
                if(map[ddx][ddy]!='X'){
                    q.push({ddx,ddy});
                }
            }
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int n = maps.size();
    int m = maps[0].length();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j]!='X'){
                answer.push_back(BFS(i,j,n,m,maps));
            }
        }
    }
    if(answer.empty()){
        return {-1};
    }
    sort(answer.begin(),answer.end());
    return answer;
}