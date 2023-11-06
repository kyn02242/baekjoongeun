#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class CNAME{
public:
    string HEAD;
    string NUM;
    int realnum;
    string TAIL;
};

bool operator < (const CNAME &ttmpCNAME,const CNAME &tmpCNAME) {
        string tmpthishead = "";
        string tmpthathead = "";
        for(int i=0;i<ttmpCNAME.HEAD.length();i++){
            tmpthishead += tolower(ttmpCNAME.HEAD[i]);
        }
        for(int i=0;i<tmpCNAME.HEAD.length();i++){
            tmpthathead += tolower(tmpCNAME.HEAD[i]);
        }
        if(tmpthishead!=tmpthathead){
		    return tmpthishead < tmpthathead;
        }
        else{
            return ttmpCNAME.realnum<tmpCNAME.realnum;
        }
	}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<CNAME> tmpv;
    for(int i=0;i<files.size();i++){
        CNAME tmpCNAME;
        string head = "";
        string num = "";
        string tail = "";
        int cnt = 0;
        bool check = false;
        for(int j=0;j<files[i].length();j++){
            if(check){
                tail+=files[i][j];
            }
            else{
                if(files[i][j]>'9'||files[i][j]<'0'){
                    if(num.empty()){
                        head+=files[i][j];
                    }
                    else{
                        tail+=files[i][j];
                        check = true;
                    }
                }
                else{
                    if(cnt<5){
                        num+=files[i][j];
                        cnt++;
                    }
                    else{
                        tail+=files[i][j];
                        check = true;
                    }
                }
            }
        }
        tmpCNAME.HEAD = head;
        tmpCNAME.NUM = num;
        // cout<<head<<endl;
        // cout<<num<<endl;
        // cout<<tail<<endl;
        tmpCNAME.realnum = stoi(num);
        tmpCNAME.TAIL = tail;
        tmpv.push_back(tmpCNAME);
    }
    stable_sort(tmpv.begin(),tmpv.end());
    
    for(int i=0;i<files.size();i++){
        string tmp = tmpv[i].HEAD+tmpv[i].NUM+tmpv[i].TAIL;
        answer.push_back(tmp);
    }

    return answer;
}
