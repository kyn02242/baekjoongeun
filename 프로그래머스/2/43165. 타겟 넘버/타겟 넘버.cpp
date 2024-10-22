#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

int answer = 0;

void DFS(vector<int> numbers, int sum, int index, int target)
{
    if (index == numbers.size())
    {
        if (target == sum)
        {
            answer++;
        }
        return;
    }
    DFS(numbers, sum + numbers[index], index + 1, target);
    DFS(numbers, sum - numbers[index], index + 1, target);
}

int solution(vector<int> numbers, int target)
{
    DFS(numbers, 0, 0, target);
    return answer;
}