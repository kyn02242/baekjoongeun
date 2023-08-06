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

vector<vector<int>> v1(101,vector<int>(101,1));
vector<vector<int>> v2(101,vector<int>(101,1));
queue<pair<int,int>> q1;
queue<pair<int,int>> q2;

int N;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void BFS(int x,int y){
    int original = v1[x][y];
    
    q1.push(make_pair(x,y));
    while(!q1.empty()){
        int xx = q1.front().first;
        int yy = q1.front().second;
        
        //cout<<original<<endl;

        v1[xx][yy] = 0;

        //cout<<v1[xx][yy]<<","<<xx<<","<<yy<<endl;

        q1.pop();

        for(int i=0;i<4;i++){
            int ddx = xx+dx[i];
            int ddy = yy+dy[i];
            if(ddx>=0&&ddy>=0&&ddx<N&&ddy<N){
                if(v1[ddx][ddy]==original){
                    q1.push(make_pair(ddx,ddy));
                    v1[ddx][ddy] = 0;
                }
            }
            
        }
    }
}
void BFS_WEAK(int x, int y){
    int original = v2[x][y];
    q2.push(make_pair(x,y));
    while(!q2.empty()){
        int xx = q2.front().first;
        int yy = q2.front().second;
        //cout<<xx<<","<<yy<<endl;
        v2[xx][yy] = 0;
        q2.pop();
        for(int i=0;i<4;i++){
            int ddx = xx+dx[i];
            int ddy = yy+dy[i];
            if(ddx>=0&&ddy>=0&&ddx<N&&ddy<N){
                if(v2[ddx][ddy]==original){
                    q2.push(make_pair(ddx,ddy));
                    v2[ddx][ddy] = 0;
                }
            }
            
        }
    }

}

int main()
{
    char tmp;
    int ans1 = 0;
    int ans2 = 0;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>tmp;
            if(tmp == 'G'){
                v1[i][j] = 1;
                v2[i][j] = 1;
            }
            if(tmp == 'R'){
                v1[i][j] = 2;
                v2[i][j] = 1;
            }
            if(tmp == 'B'){
                v1[i][j] = 3;
                v2[i][j] = 2;
            }
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout<<v1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(v1[i][j]!=0){
                BFS(i,j);
                ans1++;
            }
            if(v2[i][j]!=0){
                BFS_WEAK(i,j);
                ans2++;
            }
        }
    }
    cout<<ans1<<" "<<ans2<<endl;

    return 0;
}