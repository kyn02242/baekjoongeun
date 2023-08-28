#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int cnt1 = 0;
int cnt2 = 0;
int dele(string s){
	int tmp = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            cnt1++;
        }
        else{
            tmp++;
        }
    }
    return tmp;
}

vector<int> solution(string s) {
    vector<int> answer;
	while(1){
        cnt2++;
        int tmp = 0;
        string Tmpstring;
		tmp = dele(s);
		while(tmp!=0){
            Tmpstring+=to_string(tmp%2);
            tmp/=2;
        }
        reverse(Tmpstring.begin(),Tmpstring.end());
        s = Tmpstring;
		if(s=="1"){
			break;
		}
	}
    
    answer.push_back(cnt2);
    answer.push_back(cnt1);   
    
    return answer;
}