#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

pair<int,int> pstart;
pair<int,int> pend;
pair<int,int> plev;

int BFS(int n,int m,vector<string> &v,bool flag){//flag = 0 : 시작->레버 //flag = 1 : 레버->출구
    if(flag){//레버->출구
        queue<pair<pair<int,int>,int>> q;
        q.push({plev,0});
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int cnt = q.front().second;
            q.pop();
            //cout<<"x : "<<x<<" "<<"y : "<<y<<endl;
            if(x==pend.first&&y==pend.second){
                return cnt;
            }
            else if(v[x][y]=='C')continue;
            else v[x][y] = 'C';
            for(int i=0;i<4;i++){
                int ddx = x+dx[i];
                int ddy = y+dy[i];
                if(ddx>=0&&ddx<m&&ddy>=0&&ddy<n&&(v[ddx][ddy]=='S'||v[ddx][ddy]=='E'||v[ddx][ddy]=='O')){
                    q.push({{ddx,ddy},cnt+1});
                }
            }
            
        }
        return -1;

        
        return 0;
    }
    else{//시작->레버
        queue<pair<pair<int,int>,int>> q;
        q.push({pstart,0});
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int cnt = q.front().second;
            q.pop();
            //cout<<"x : "<<x<<" "<<"y : "<<y<<endl;
            if(x==plev.first&&y==plev.second){
                return cnt;
            }
            else if(v[x][y]=='C')continue;
            else v[x][y] = 'C';
            for(int i=0;i<4;i++){
                int ddx = x+dx[i];
                int ddy = y+dy[i];
                if(ddx>=0&&ddx<m&&ddy>=0&&ddy<n&&(v[ddx][ddy]=='E'||v[ddx][ddy]=='L'||v[ddx][ddy]=='O')){
                    q.push({{ddx,ddy},cnt+1});
                }
            }
            
        }
        return -1;
    }
}

int solution(vector<string> maps) {
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(cnt == 3)break;
        for(int j=0;j<m;j++){
            if(cnt == 3)break;
            if(maps[i][j]=='S'){
                pstart = {i,j};
                cnt++;
            }
            if(maps[i][j]=='E'){
                pend = {i,j};
                cnt++;
            }
            if(maps[i][j]=='L'){
                plev = {i,j};
                cnt++;
            }
        }
    }
    int ans1 = BFS(m,n,maps,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j]=='C')maps[i][j]='O';
        }
    }
    int ans2 = BFS(m,n,maps,1);
    if(ans1!=-1&&ans2!=-1){
        answer = ans1+ans2;
        return answer;
    }
    else return -1;
}
