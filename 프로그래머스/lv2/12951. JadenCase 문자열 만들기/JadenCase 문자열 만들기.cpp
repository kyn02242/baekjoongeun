#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    for(int i=0;i<s.length();i++){
        if(i==0&&s[i]>='a'&&s[i]<='z'){
            s[i]+='A'-'a';
            continue;
        }
        if(s[i-1]==' '&&s[i]>='a'&&s[i]<='z'&&i>0){
            s[i]+='A'-'a';
            continue;
        }
        else if(s[i-1]!=' '&&s[i]>='A'&&s[i]<='Z'&&i>0){
            s[i]+='a'-'A';
        }
    }
    answer = s;
    
    return answer;
}