#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isprime(int n){
    if(n==1){
        return false; 
    }
    if(n==2)return true;
    for(int i=2;i<sqrt(n)+1;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

bool isinclude(string st,int n){
    //cout<<n<<endl;
    string tmp = to_string(n);
    //cout<<tmp<<endl;
    int ans=0;
    for(int i=0;i<tmp.length();i++){
        for(int j=0;j<st.length();j++){
            if(tmp[i]==st[j]){
                //cout<<i<<endl;
                //cout<<"tmp : "<<tmp[i]<<" "<<"st : "<<st[j]<<endl;
                ans++;
                st[j] = '-';
                break;
            }
        }
    }
    if(tmp.length()==ans){
        return true;
    }
    return false;
}

int solution(string numbers) {
    int answer = 0;
    string n = numbers;
    sort(n.rbegin(),n.rend());
    
    for(int i=2;i<=stoi(n);i++){
        if(isprime(i)){
            //cout<<"prime num : "<<i<<endl;
            if(isinclude(numbers,i)){
                answer++;
                //cout<<"include num : "<<i<<endl;
            }
        }
    }
    return answer;
}
