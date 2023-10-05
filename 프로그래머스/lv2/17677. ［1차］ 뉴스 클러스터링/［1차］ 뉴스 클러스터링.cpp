#include <string>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    double d;
    vector<string> v1;
    vector<string> v2;
    double cnt1 = 0;
    double cnt2 = 0;
    transform(str1.begin(), str1.end(),str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(),str2.begin(), ::toupper);
    for(int i=0;i<str1.size()-1;i++){
        if(str1[i]>='A'&&str1[i+1]>='A'&&str1[i]<='Z'&&str1[i+1]<='Z'){
            string tmp;
            tmp+=str1[i]+32;
            tmp+=str1[i+1]+32;
            v1.push_back(tmp);
        }
    }
    for(int i=0;i<str2.size()-1;i++){
        if(str2[i]>='A'&&str2[i+1]>='A'&&str2[i]<='Z'&&str2[i+1]<='Z'){
            string tmp;
            tmp+=str2[i]+32;
            tmp+=str2[i+1]+32;
            v2.push_back(tmp);
        }
    }
    // for(int i=0;i<v1.size();i++){
    //     cout<<"v1["<<i<<"] : "<<v1[i]<<endl;
    // }
    // for(int i=0;i<v2.size();i++){
    //     cout<<"v2["<<i<<"] : "<<v2[i]<<endl;
    // }
    while(1){
        if(v1.empty()||v2.empty()){
            cnt2+=v1.size()+v2.size();
            break;
        }
        for(int i=v2.size()-1;i>=0;i--){
            if(v2[i]==v1[v1.size()-1]){
                cnt1++;
                cnt2++;
                v2[i] = v2[v2.size()-1];
                v1.pop_back();
                v2.pop_back();
                break;
            }
            if(i==0){
                cnt2++;
                v1.pop_back();
            }
        }
    }
    //cout<<cnt1<<","<<cnt2<<endl;
    if(cnt2==0){
        answer = 65536;
        return answer;
    }
    d = cnt1/cnt2;
    answer = d*65536;
    return answer;
}
