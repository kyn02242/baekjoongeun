#include <string>
#include <map>

using namespace std;

map<pair<pair<int, int>, pair<int, int>>, int> mp;

int solution(string dirs) {
    int answer = 0;
    pair<int, int> start = { 0,0 };
    for (int i = 0; i < dirs.length(); i++) {
        pair<int, int> end = start;
        if (dirs[i] == 'U') {
            if (start.second == 5) {
                end = start;
            }
            else {
                end = { start.first,start.second + 1 };
            }
        }
        else if (dirs[i] == 'D') {
            if (start.second == -5) {
                end = start;
            }
            else {
                end = { start.first,start.second - 1 };
            }
        }
        else if (dirs[i] == 'R') {
            if (start.first == 5) {
                end = start;
            }
            else {
                end = { start.first + 1,start.second };
            }
        }
        else if (dirs[i] == 'L') {
            if (start.first == -5) {
                end = start;
            }
            else {
                end = { start.first - 1,start.second };
            }
        }
        else {
            return -1;
        }

        if (mp[{start, end}] != 0) {
            mp[{start, end}]++;
        }
        else if (mp[{end, start}] != 0) {
            mp[{end,start}]++;
        }
        else {
            mp[{start, end}]++;
        }
        start = end;
    }
    for (const auto& itor : mp) {
        //cout<<"start : " << itor.first.first.first<<","<< itor.first.first.second<<"  end :"<< itor.first.second.first<<","<< itor.first.second.second << " : " << itor.second << endl;
        if (itor.first.first != itor.first.second && itor.second!=0) {
            answer++;
        }
    }

    return answer;
}
