#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

map<string, string> mp;

pair<string,string> spliting(string s) {
    vector<string> result;
    stringstream ss(s);
    string tmp;
    while (getline(ss, tmp, ' ')) {
        result.push_back(tmp);
    }
    return make_pair(result[1], result[2]);
}

string spliting_leave(string s) {
    vector<string> result;
    stringstream ss(s);
    string tmp;
    while (getline(ss, tmp, ' ')) {
        result.push_back(tmp);
    }
    return result[1];
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<char, string>> tmp;
    for (int i = 0; i < record.size(); i++) {
        pair<string, string> stp;
        if (record[i][0] == 'E') {//enter
            stp = spliting(record[i]);
            mp[stp.first] = stp.second;
            tmp.push_back(make_pair('E', stp.first));
        }
        else if (record[i][0] == 'C') {//change
            stp = spliting(record[i]);
            mp[stp.first] = stp.second;
        }
        else {//leave
            string ttmp = spliting_leave(record[i]);
            tmp.push_back(make_pair('L', ttmp));
        }
    }

    for (int i = 0; i < tmp.size(); i++) {
        string stmp;
        if (tmp[i].first == 'E') {
            stmp = mp[tmp[i].second] + "님이 들어왔습니다.";
            answer.push_back(stmp);
        }
        else {
            stmp = mp[tmp[i].second] + "님이 나갔습니다.";
            answer.push_back(stmp);
        }
    }
    return answer;
}