#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> mp;
    for (int i = 0; i < skill.size(); i++) {
        mp[skill[i]] = i+1;
    }

    for (int i = 0; i < skill_trees.size(); i++) {
        int cnt = 1;
        for (int j = 0; j < skill_trees[i].size(); j++) {
            if (mp[skill_trees[i][j]] != 0 && mp[skill_trees[i][j]] == cnt) {
                cnt++;
            }
            else if (mp[skill_trees[i][j]] != 0 && mp[skill_trees[i][j]] != cnt) {
                cnt = 0;
                break;
            }
        }
        if (cnt != 0) {
            answer++;
        }
    }
    return answer;
}