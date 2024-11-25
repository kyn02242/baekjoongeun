#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <deque>
#include <numeric>
#define endl '\n'
#define LINE cout << endl
#define MAX INT32_MAX

using namespace std;

bool line[51][51];
bool visited[51] = {
    false,
};
queue<int> q;

void BFS(int start, int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        if (line[start][i] && !visited[i])
        {
            q.push(i);
            visited[i] = true;
        }
    }
    while (!q.empty())
    {
        int tp = q.front();
        q.pop();
        for (int i = 1; i < n + 1; i++)
        {
            if (line[tp][i] && !visited[i]) // 방문하지 않았고, 해당 사람과 같은 파티를 참석할 때(간선이 존재할 때)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

bool canLie(vector<int> party){ //거짓말 가능한지 여부 반환
    for(auto i : party){
        if(visited[i]){
            return false;
        }
    }
    return true;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int tmp, ttmp;

    // 진실을 아는 사람 입력
    cin >> tmp;
    vector<int> truthVector;
    vector<vector<int>> party(m, vector<int>());

    for (int i = 0; i < tmp; i++)
    {
        cin >> ttmp;
        truthVector.push_back(ttmp);
        visited[ttmp] = true;
    }

    // 파티 참석 인원 입력
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        for (int j = 0; j < tmp; j++)
        {
            cin >> ttmp;
            party[i].push_back(ttmp);
        }

        // 같은 파티를 참석하는 인원들 서로 연결
        for (int j = 0; j < tmp; j++)
        {
            for (int k = 0; k < tmp; k++)
            {
                line[party[i][j]][party[i][k]] = true;
                line[party[i][k]][party[i][j]] = true;
            }
        }
    }

    // 전체 BFS로 진실 여부를 기록한 후에
    for (int i = 0; i < truthVector.size(); i++)
    {
        BFS(truthVector[i], n);
    }


    // 진실 여부에 따라 파티의 진실 여부를 결정
    int count = 0;
    for(int i =0;i<m;i++){
        if(canLie(party[i])){
            count++;
        }
    }
    cout << count;

    return 0;
}