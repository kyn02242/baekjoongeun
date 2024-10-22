#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    stack<int> st;

    st.push(arr[0]);
    answer.push_back(arr[0]);

    for (auto i : arr)
    {
        if (st.top() != i)
        {
            st.push(i);
            answer.push_back(i);
        }
    }
    return answer;
}