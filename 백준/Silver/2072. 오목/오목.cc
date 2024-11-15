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
#define endl '\n'
#define MAX INT_MAX

using namespace std;

vector<vector<int>> v(21, vector<int>(21, -1));

int countStreak(int x, int y, int dx, int dy, bool flag, int count)
{ // 판별할 좌표, 판별할 방향, 현재까지 카운트된 수
    if (x <= 0 || y <= 0 || x >= 20 || y >= 20)
    {
        return count;
    }

    if (v[x][y] == (int)flag)
    {
        return countStreak(x + dx, y + dy, dx, dy, flag, count + 1);
    }
    else
    {
        return count;
    }
}

bool checkWin(int x, int y, bool flag)
{ // 판 전체와 마지막에 놓은 수 좌표, 흑백
    // 각 방향으로 몇개가 연속으로 동일한지 확인

    // 남 + 북
    if (countStreak(x, y, 1, 0, flag, 0) + countStreak(x, y, -1, 0, flag, 0) - 1 == 5)
    {
        return true;
    }

    // 동 + 서
    if (countStreak(x, y, 0, 1, flag, 0) + countStreak(x, y, 0, -1, flag, 0) - 1 == 5)
    {
        return true;
    }

    // 북서 + 남동
    if (countStreak(x, y, -1, 1, flag, 0) + countStreak(x, y, 1, -1, flag, 0) - 1 == 5)
    {
        return true;
    }

    // 북동 + 남서
    if (countStreak(x, y, 1, 1, flag, 0) + countStreak(x, y, -1, -1, flag, 0) - 1 == 5)
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int tmpx, tmpy;
    bool flag = true;
    int answer = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> tmpx >> tmpy;
        if (flag)
        {
            v[tmpx][tmpy] = 1;
        }
        else
        {
            v[tmpx][tmpy] = 0;
        }

        if (checkWin(tmpx, tmpy, flag) && answer == -1)
        {
            answer = i + 1;
        }

        flag = !flag;
    }
            // // 판 출력
            // for (int i = 1; i < 20; i++)
            // {
            //     for (int j = 1; j < 20; j++)
            //     {
            //         cout << v[i][j] << ' ';
            //     }
            //     cout << endl;
            // }

    cout << answer;

    return 0;
}