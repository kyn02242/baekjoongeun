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

// 뺀 결과
// 상수 = 0 - 무한대
// 상수 != 0 - 0
// 일차함수 - 무조건 1개의 답
// 이차함수 - 공식을 통한 판별
//

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int f1, f2, f3, g1, g2;

    cin >> f1 >> f2 >> f3;
    cin >> g1 >> g2;

    int p1, p2, p3;
    int q1, q2, q3;

    p1 = pow(g1, 2) * f1;
    p2 = g1 * g2 * 2 * f1 + f2 * g1;
    p3 = pow(g2, 2) * f1 + f2 * g2 + f3;

    q1 = g1 * f1;
    q2 = f2 * g1;
    q3 = f3 * g1 + g2;

    // cout << p1 << ' ' << p2 << ' ' << p3 << endl;
    // cout << q1 << ' ' << q2 << ' ' << q3 << endl;

    int ans1 = p1 - q1;
    int ans2 = p2 - q2;
    int ans3 = p3 - q3;

    if (ans1 == 0 && ans2 == 0) // 상수일때
    {
        if (ans3 == 0)
        {
            cout << "Nice";
        }
        else
        {
            cout << "Head on";
        }
    }
    else if (ans1 == 0) // 일차 함수일때
    {
        cout << "Remember my character";
    }
    else // 이차 함수일때
    {
        int ans = pow(ans2, 2) - 4 * (ans1) * (ans3);
        if (ans == 0)
        {
            cout << "Remember my character";
        }
        if (ans > 0)
        {
            cout << "Go ahead";
        }
        if (ans < 0)
        {
            cout << "Head on";
        }
    }

    return 0;
}