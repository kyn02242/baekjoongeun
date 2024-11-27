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

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(1001);
    vector<int> dp(1001);
    vector<int> dpR(1001);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j <= i; j++)
        {
            if (v[j] < v[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    for (int i = n; i >= 1; i--)
    {
        dpR[i] = 1;
        for (int j = n; j >= i; j--)
        {
            if (v[i] > v[j] && dpR[j] + 1 > dpR[i])
            {
                dpR[i] = dpR[j] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (ans < dp[i] + dpR[i] - 1)
        {
            ans = dp[i] + dpR[i] - 1;
        }
    }
    cout << ans;

    return 0;
}