#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    int answer = enemy.size();
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < enemy.size(); i++)
    {
        pq.push(enemy[i]);
        if (pq.size() > k)
        {
            sum += pq.top();
            pq.pop();
        }
        if (sum > n) return i;
    }
    return answer;
}