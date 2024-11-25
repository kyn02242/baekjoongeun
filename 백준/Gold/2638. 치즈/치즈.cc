#include <string>
#include <string.h>
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

int board[100][100] = {
    0,
};

bool visited[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
int cheeseCount = 0;

void checkAir(int x = 0, int y = 0)
{ // 어떤 지점을 기준으로 미방문 지역 방문하며 갱신
    // 만약 인자가 없다면(맨 처음 동작이라면) 0,0 지점부터 연결된 전체 보드를 확인
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ddx = x + dx[i];
            int ddy = y + dy[i];

            if (ddx >= 0 && ddx < n && ddy >= 0 && ddy < m)
            {
                if (!visited[ddx][ddy])
                {
                    if (board[ddx][ddy] >= 1)
                    { // 외부공기와 접촉한 치즈는 ++ --> 삭제될 치즈는 3이상의 값을 가지게 된다.
                        // 방문 기록은 변경하지 않아야 접촉 면 수가 정확하게 기록된다.
                        board[ddx][ddy]++;
                    }
                    else if (board[ddx][ddy] == -1)
                    { // 외부 공기면 방문 여부만 작성한 후 큐에 삽입
                        visited[ddx][ddy] = true;
                        q.push(make_pair(ddx, ddy));
                    }
                    else if (board[ddx][ddy] == 0)
                    { // 내부공기(혹은 아직 갱신되지 않은 외부 공기)라면 방문으로 기록하고, 해당 값을 -1로 바꾼 뒤, 큐에 삽입
                        visited[ddx][ddy] = true;
                        board[ddx][ddy] = -1;
                        q.push(make_pair(ddx, ddy));
                    }
                }
            }
        }
    }
}

void removeCheese() // 외부공기 2면이상 접촉 치즈 삭제
{
    // 삭제 및 갱신 과정에서 연쇄적으로 반응하는것을 방지하기위해 큐
    queue<pair<int, int>> q;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (board[i][j] >= 3)
            {
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty())
    {
        cheeseCount--;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // 외부 공기 칸으로 바꾸기
        board[x][y] = -1;
        // 해당 지점에서 연결된 미방문(치즈, 내부공기)를 갱신한다.
        checkAir(x, y);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    fill(visited[0], visited[100], false); // 방문 기록 초기화

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 1){
                cheeseCount++;
            }
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) // 테두리는 외부공기
            {
                board[i][j] = -1;
            }
        }
    }
    checkAir();

    int answer = 0;
    while(cheeseCount > 0){
        removeCheese();
        answer++;
    }

    cout << answer;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << board[i][j] << ' ';
    //     }
    //     LINE;
    // }

    return 0;
}