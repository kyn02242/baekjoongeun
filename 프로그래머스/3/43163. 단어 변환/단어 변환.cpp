#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<string,int>> q; // string과 그의 단계 저장

int countDiff(string a, string b)
{
    int sum = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            sum++;
        }
    }
    return sum;
}

int BFS(vector<string> words, vector<bool> visited, string begin, string target, int n)
// 시작하는 begin단어를 큐에 넣고 걔부터 계산을 시작한다.
// words를 순회하면서 차이가 1인 단어를 찾고, 해당 단어를 큐에 넣는다.
// 큐에서 뺐는데 해당 단어가 target단어라면 거기까지 필요한 단계를 리턴한다.
{
    q.push({begin, 0});
    while (!q.empty())
    {
        string now = q.front().first;
        int step = q.front().second;

        q.pop();

        if(now == target){
            return step;
        }

        for (int i = 0; i < n; i++)
        {
            if (countDiff(now, words[i]) == 1 && visited[i] == false) // 하나 차이인데 단계가 아직 기록되지 않은 경우
            {
                visited[i] = true;
                q.push({words[i], step + 1});
            }
        }
    }

    return 0;
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    int n = words.size();
    vector<bool> visited(n, false);
    answer = BFS(words, visited, begin, target, n);
    return answer;
}