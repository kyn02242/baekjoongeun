#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    for(int i=0;i<=citations.size();i++){
        int cnt = 0;
        for(int j=0;j<citations.size();j++){
            if(i<=citations[j]){
                cnt++;
            }
        }
        if(cnt>=i){
            answer = i;
        }
    }
    return answer;
}