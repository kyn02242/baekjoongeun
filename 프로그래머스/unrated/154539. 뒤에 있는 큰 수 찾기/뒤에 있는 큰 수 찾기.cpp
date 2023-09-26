#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<pair<int,int>> st;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(),-1);
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
    return answer;
}