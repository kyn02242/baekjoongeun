#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

vector<vector<int>> v(128, vector<int>(128));

int ans_white = 0;
int ans_blue = 0;

void check(int x, int y, int size)
{
    if(size == 1){
        if(v[x][y]==1){
            ans_blue++;
            // cout<<x<<" "<<y<<endl;
            // cout<<"1"<<endl;
        }
        else{
            ans_white++;
            // cout<<x<<" "<<y<<endl;
            // cout<<"2"<<endl;
        }
        return;
    }
    int sum = 0;
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            sum += v[i][j];
        }
    }
    if(sum == 0||sum==size*size){
        if(sum==0){
            ans_white++;
            // cout<<x<<" "<<y<<endl;
            // cout<<"3"<<endl;
        }
        else{
            ans_blue++;
            // cout<<x<<" "<<y<<endl;
            // cout<<"4"<<endl;
        }
        return;
    }
    else{
        check(x,y,size/2);
        check(x+size/2,y,size/2);
        check(x,y+size/2,size/2);
        check(x+size/2,y+size/2,size/2);
        return;
    }
    return;
}

int main()
{

    // 크기와 시작점이 주어질 때, 해당 점을 왼쪽 위로 하는 정사각형이 채워져있는지?, 채워져있지 않다면 다시 돌리기
    
    int size;
    cin>>size;
    for(int i = 0;i<size;i++){
        for(int j  =0;j<size;j++){
            cin>>v[i][j];
        }
    }

    check(0,0,size);

    cout<<ans_white<<endl;
    cout<<ans_blue<<endl;


    return 0;
}