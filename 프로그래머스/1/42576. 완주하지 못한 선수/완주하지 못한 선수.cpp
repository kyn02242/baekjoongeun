#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> mp;
    for(auto i : completion)
    {
        if(mp.end() == mp.find(i)) // 맵 안에 i값 없으면
            mp.insert(make_pair(i, 1)); // 키로 만들어서 넣기
        else
            {mp[i]++;}
    }

    for(auto i : participant)
    {
        if(mp.end() == mp.find(i)) // i값 없으면
        {
            answer = i;
            break;
        }
        else
        {
            mp[i]--;
            if(mp[i] < 0) // i값은 있는데 음수이면 -> 동명이인이 완주 못함
            {
                answer = i;
                break;
            }
        }
    }
    return answer;
}