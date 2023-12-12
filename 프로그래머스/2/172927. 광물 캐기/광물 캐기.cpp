#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<vector<int>> v(minerals.size()/5+1,vector<int>(3));
    int flag = 0;
    for(int i=0;i<minerals.size();i++){
        if(minerals[i]=="diamond"){
            v[flag][0]++;
        }
        else if(minerals[i]=="iron"){
            v[flag][1]++;
        }
        else{
            v[flag][2]++;
        }
        if(i%5==4)flag++;
    }
    
    int num = 0;
    for(int i=0;i<3;i++){
        num+=picks[i];
    }
    if(num>=v.size()){
        num = v.size();
    }
    sort(v.begin(),v.begin()+num,greater<>());
    flag = 0;

    // for(int i=0;i<v.size();i++){
    //     for(int j=0;j<v[i].size();j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0;i<num;i++){
        while(picks[flag]==0){
            flag++;
        }
        picks[flag]--;
        if(flag == 0){
            answer += v[i][0]+v[i][1]+v[i][2];
        }
        else if(flag==1){
            answer += 5*v[i][0]+v[i][1]+v[i][2];
        }
        else{
            answer += 25*v[i][0]+5*v[i][1]+v[i][2];
        }    
        if(picks[flag]==0){
            if(flag == 2){
                break;
            }
            else{
                flag++;
            }
        }
    }
    return answer;
}