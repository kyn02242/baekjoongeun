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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int tmp;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp < 0)
        {
            tmp = -1 * tmp;
        }
        total += tmp;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp > 0)
        {
            tmp = -1 * tmp;
        }
        total -= tmp;
    }

    cout << total;

    return 0;
}