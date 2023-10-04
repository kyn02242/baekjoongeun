#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cnt = 1;
    queue<pair<int,int>> q;
    int n = priorities.size();
    for(int i=0;i<n;i++){
        q.push(make_pair(i,priorities[i]));
    }
    sort(priorities.begin(),priorities.end());
    while(!q.empty()){
        if(q.front().second==priorities[priorities.size()-1]){
            if(q.front().first==location){
                answer = cnt;
                break;
            }
            cnt++;
            q.pop();
            priorities.pop_back();
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    
    return answer;
}