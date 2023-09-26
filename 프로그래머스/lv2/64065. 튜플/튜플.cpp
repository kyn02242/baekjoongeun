#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> mp;
    string tmp = "";

    for (int i = 1; i < s.length()-1; i++) {
        if (s[i] == '{') {}

        else if (s[i] >= '0' && s[i] <= '9') {
            tmp += s[i];
        }
        else if(s[i] == ','&&s[i-1]=='}'){
            
        }
        else {
            mp[stoi(tmp)]++;
            tmp = "";
        }
    }

    vector<pair<int, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp);

    for (auto itor : v) {
        answer.push_back(itor.first);
    }
    return answer;
}