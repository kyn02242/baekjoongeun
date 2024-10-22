#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size();
    int flag = 1;
    vector<int> v;

    sort(nums.begin(), nums.end());

    v.push_back(nums[0]);
    for (auto i : nums)
    {
        if (v.back() != i)
        {
            v.push_back(i);
        }
    }

    if (v.size() >= n / 2)
    {
        answer = n / 2;
    }
    else
    {
        answer = v.size();
    }

    return answer;
}