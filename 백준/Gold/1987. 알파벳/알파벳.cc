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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int r, c, answer;
char board[20][20];
bool visited[26] = {
    false,
};

void DFS(int x, int y, int cnt) // 현재 지점부터 갈 수 있는 최대 거리를 리턴한다
{
    // cout << "x : " << x << " / y : " << y << endl;
    answer = max(answer, cnt);
    for (int i = 0; i < 4; i++)
    {
        if (x + dx[i] >= 0 && x + dx[i] < r && y + dy[i] >= 0 && y + dy[i] < c)
        {
            int ddx = x + dx[i];
            int ddy = y + dy[i];

            if (!visited[board[ddx][ddy] - 'A'])
            { // 다음 지점에 간적 없으면
                visited[board[ddx][ddy] - 'A'] = true;
                DFS(ddx, ddy, cnt + 1);
                // 왔던 기록 삭제
                // 다른 루트를 방해하지 않도록
                visited[board[ddx][ddy] - 'A'] = false;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 판을 입력 받는다
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
        }
    }

    // DFS를 통해 가장 깊게 이동한 경우를 찾는다
    visited[board[0][0] - 'A'] = true;
    DFS(0, 0, 1);

    // 해당 경우의 길이를 출력한다
    cout << answer;

    return 0;
}