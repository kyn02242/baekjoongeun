#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    for(int i=1;i<=order.size();i++){
        s.push(i);
        while(!s.empty()&&s.top()==order[answer]){
            s.pop();
            answer++;
        }
    }
    
    
    return answer;
}