#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets)
{
    int answer = 0;
    int i = 0;
    sort(targets.begin(), targets.end());
    while (i < targets.size())
    {
        int end = targets[i][1];
		i++;
        answer++;
        while (i < targets.size() && targets[i][0] < end)
        {
            if (targets[i][1] < end) end = targets[i][1];
            i++;
        }
    }
    return answer;
}