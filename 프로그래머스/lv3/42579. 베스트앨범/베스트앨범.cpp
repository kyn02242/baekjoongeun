#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string,int> mpcnt;
map<string,map<int,int>> mpout;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i=0;i<genres.size();i++){
        mpcnt[genres[i]]+=plays[i];
        mpout[genres[i]][i] = plays[i];
    }
    
    while(!mpcnt.empty()){
        string tmpstring;
        int max = 0;
        for(auto iter : mpcnt){
            if(iter.second>max){
                max = iter.second;
                tmpstring = iter.first;
            }
        }
        for(int i=0;i<2;i++){
            int max2=0;
            int ansidx;
            bool check = false;
            for(auto iter : mpout[tmpstring]){
                if(max2 < iter.second){
                    max2 = iter.second;
                    ansidx = iter.first;
                    check = true;
                }
            }
            if(check){
                answer.push_back(ansidx);
                mpout[tmpstring].erase(ansidx);
            }
        }
        mpcnt.erase(tmpstring);
    }
    
    
    
    
    return answer;
}