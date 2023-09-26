#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<pair<int,int>> st;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    for (int i = 0; i < numbers.size(); i++)
    {
        while (!st.empty())
        {
            if (st.top().first >= numbers[i])
            {
                break;
            }
            answer[st.top().second] = numbers[i];
            st.pop();
        }
        st.push(make_pair(numbers[i], i));
    }
    for(int i=0;i<numbers.size();i++){
        if(answer[i]==0){
            answer[i] = -1;
        }
    }
    return answer;
}