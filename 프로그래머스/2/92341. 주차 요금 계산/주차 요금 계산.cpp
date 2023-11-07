#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<int, vector<int>> mp;
    for (int i = 0; i < records.size(); i++)
    {
        string h = "";
        string m = "";
        string num = "";
        int time = 0;
        h += records[i][0];
        h += records[i][1];
        m += records[i][3];
        m += records[i][4];
        time += stoi(h) * 60 + stoi(m);
        num += records[i][6];
        num += records[i][7];
        num += records[i][8];
        num += records[i][9];
        mp[stoi(num)].push_back(time);
    }
    for (auto i : mp)
    {
        int endtime = 23 * 60 + 59;
        int time = 0;
        int totalfee = 0;

        if (i.second.size() % 2 != 0)
        {
            i.second.push_back(endtime);
        }

        for (int j = 0; j < i.second.size(); j++)
        {
            if (j % 2 == 0)
            {
                time -= i.second[j];
            }
            else
            {
                time += i.second[j];
            }
        }

        totalfee += fees[1];
        time -= fees[0];
        if (time > 0)
        {
            totalfee += (time / fees[2]) * fees[3];
            if (time % fees[2] != 0)
            {
                totalfee += fees[3];
            }
        }
        answer.push_back(totalfee);
    }

    return answer;
}
