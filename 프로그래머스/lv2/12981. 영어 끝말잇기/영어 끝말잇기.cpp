#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    for(int i=0;i<words.size();i++){
        if(i==0){
            continue;
        }
        else if(words[i-1][words[i-1].size()-1]!=words[i][0]){
            int ans1 = i%n+1;
            int ans2 = i/n+1;
            answer.push_back(ans1);
            answer.push_back(ans2);
            return answer;
        }
        else{
            for(int j=0;j<i;j++){
                if(words[j]==words[i]){
                    int ans1 = i%n+1;
                    int ans2 = i/n+1;
                    answer.push_back(ans1);
                    answer.push_back(ans2);
                    return answer;
                }
            }
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    
    return answer;
}