#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> v({"0","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"});

int check(string st){
    for(int i=v.size()-1;i>0;i--){
        if(v[i]==st){
            return i;
        }
    }
    return -1;
}

vector<int> solution(string msg) {
    stack<string> st;
    reverse(msg.begin(),msg.end());
    for(auto i : msg){
        st.push(string(1,i));
    }
    vector<int> answer;
    string tmp;
    int flag;
    while(!st.empty()){
        

        if(tmp==""){
            //cout<<"1"<<endl;
            flag = check(st.top());
            tmp = st.top();
            st.pop();
        }
        //cout<<"tmp : "<<tmp<<endl;
        if(st.empty()){
            answer.push_back(flag);
            break;
        }

        if(-1!=check(tmp+st.top())){
            //cout<<"2"<<endl;
            flag = check(tmp+st.top());
            tmp += st.top();
            st.pop();
            if(st.empty()){
            answer.push_back(flag);
            break;
            }
            continue;
        }
        else{
            //cout<<"3"<<endl;
            answer.push_back(flag);
            v.push_back(tmp+st.top());
            tmp = "";
        }
        // for(auto i : v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
    }
    
    
    return answer;
}