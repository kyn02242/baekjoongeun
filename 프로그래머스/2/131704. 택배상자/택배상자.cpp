#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> st;
    for(int i=1;i<=order.size();i++){
        st.push(i);
        while(!st.empty()&&st.top()==order[answer]){
            st.pop();
            answer++;
        }
    }
    return answer;
}