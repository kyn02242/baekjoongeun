#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<long long>> v(101,vector<long long>(101));
vector<vector<long long>> many(101,vector<long long>(101));
queue<pair<int,int>> q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void BFS(int m,int n){
    q.push(make_pair(0,0));
    many[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ddx = x+dx[i];
            int ddy = y+dy[i];
            if(ddx>=m||ddy>=n||ddx<0||ddy<0){
                continue;
            }
            if(ddx==m-1&&ddy==n-1){//도착하면
                if(v[m-1][n-1]==0){//비어있으면
                    v[m-1][n-1] = v[x][y]+1;
                    many[ddx][ddy] = many[x][y]%1000000007;
                }
                else{
                    if(v[m-1][n-1]==v[x][y]+1){
                        many[ddx][ddy]+=many[x][y]%1000000007;
                        many[ddx][ddy] %= 1000000007;
                    }
                    else if(v[m-1][n-1]>v[x][y]+1){
                        many[m-1][n-1] = 1;
                        v[m-1][n-1] = v[x][y]+1;
                    }
                }
            }
            else{//도착지점이 아니면
                if(v[ddx][ddy]==-1){//웅덩이면
                    continue;
                }
                else{//웅덩이 아니면
                    if(v[ddx][ddy]==0){
                        v[ddx][ddy] = v[x][y]+1;
                        many[ddx][ddy] = many[x][y]%1000000007;
                        q.push(make_pair(ddx,ddy));
                    }
                    else if(v[ddx][ddy]==v[x][y]+1){
                        many[ddx][ddy]+=many[x][y]%1000000007;
                        many[ddx][ddy] %= 1000000007;
                    }
                }
            }
        }
    }
    
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i=0;i<puddles.size();i++){
        v[puddles[i][0]-1][puddles[i][1]-1] = -1;
    }
    v[0][0] = 1;
    BFS(m,n);
    
    answer = many[m-1][n-1]%1000000007;

    return answer;
}