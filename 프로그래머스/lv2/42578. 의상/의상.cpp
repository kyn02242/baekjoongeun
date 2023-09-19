#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> mp;
    vector<int> v(30);
    int flag = 0;
    for(int i=0;i<clothes.size();i++){
        if(mp.find(clothes[i][1])!=mp.end()){
            v[mp[clothes[i][1]]]++;
        }
        else{
            mp.insert({clothes[i][1],flag});
            v[flag]++;
            flag++;
        }
    }
    for(int i=0;i<flag;i++){
        answer*=v[i]+1;
    }
    answer--;
    return answer;
}