#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<pair<int,int>> st;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    for(int i=0;i<prices.size();i++){
        while(!st.empty()){
            if(st.top().first>prices[i]){
                answer[st.top().second] = i-st.top().second;
                st.pop();
            }
            else{
                break;
            }
        }
        st.push(make_pair(prices[i],i));
    }
    for(int i=0;i<prices.size();i++){
        if(answer[i] == 0){
            answer[i] = answer.size()-i-1;
        }
    }
    
    return answer;
}