#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void inserting(int num){
    v.push_back(num);
}

void deleting(int op,bool before){
    if(v.size()==0){
            return;
    }
    
    if(op==1){//max out
        if(!before){
            sort(v.begin(),v.end());
        }
        v.pop_back();
    }
    else{//min out
        if(!before){
            sort(v.begin(),v.end());
        }
        v.erase(v.begin());
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(int i=0;i<operations.size();i++){
        char command = operations[i][0];
        int num = atoi(&operations[i][2]);
        if(command=='I'){
            inserting(num);
        }
        else{
            if(i>0&&operations[i-1][0]=='D'){
                deleting(num,true);
            }
            else{
                deleting(num,false);
            }
        }
    }
    
    if(v.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        sort(v.begin(),v.end());
        answer.push_back(v.back());
        answer.push_back(v.front());
    }
    
    return answer;
}