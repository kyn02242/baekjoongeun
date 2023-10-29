#include<vector>
#include<queue>
#include<iostream>
#include<map>

using namespace std;

int n;
int m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> q;
int ans = 0;

int BFS(vector<vector<int>> &maps){
    q.push({0,0});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ddx = x+dx[i];
            int ddy = y+dy[i];
            if(ddx == n-1&&ddy == m-1){
                maps[ddx][ddy]+=maps[x][y];
                return maps[ddx][ddy];
            }
            if(ddx>=0&&ddx<n&&ddy>=0&&ddy<m&&maps[ddx][ddy]==1){
                q.push({ddx,ddy});
                maps[ddx][ddy]+=maps[x][y];
            }
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    answer = BFS(maps);
    return answer;
}