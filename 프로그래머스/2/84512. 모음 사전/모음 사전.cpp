#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string word) {
    int answer = 0;
    string ch[6] = {"N","A","E","I","O","U"};
    vector<string> st;
    int flag = 0;
    for(int a=1;a<6;a++){
        for(int b=0;b<6;b++){
            for(int c=0;c<6;c++){
                for(int d=0;d<6;d++){
                    for(int e=0;e<6;e++){
                        string tmp;
                        tmp = ch[a]+ch[b]+ch[c]+ch[d]+ch[e];
                        tmp.erase(remove(tmp.begin(),tmp.end(),'N'),tmp.end());
                        bool check = false;
                        for(int i=0;i<st.size();i++){
                            if(tmp==st[i]){
                                check = true;
                                break;
                            }
                        }
                        if(!check){
                            st.push_back(tmp);
                        }
                    }
                }
            }
        }
    }
    sort(st.begin(),st.end());
    for(int i=0;i<st.size();i++){
        if(st[i]==word){
            answer=i+1;
            break;
        }
    }
    
    
    return answer;
}