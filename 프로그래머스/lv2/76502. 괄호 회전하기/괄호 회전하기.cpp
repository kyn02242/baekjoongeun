#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(string s){
    stack<char> stk;
    stk.push(s[0]);
    for(int i=1;i<s.length();i++){
        if(s[i]==')'&&stk.top()=='('){
            stk.pop();
            continue;
        }
        if(s[i]=='}'&&stk.top()=='{'){
            stk.pop();
            continue;
        }
        if(s[i]==']'&&stk.top()=='['){
            stk.pop();
            continue;
        }
        stk.push(s[i]);
    }
    return stk.empty();
}

int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.length();i++){
        if(check(s)){
            answer++;
        }
        char tmp = s[0];
        for(int j=1;j<s.length();j++){
            s[j-1] = s[j];
        }
        s[s.length()-1]=tmp;
    }
    return answer;
}