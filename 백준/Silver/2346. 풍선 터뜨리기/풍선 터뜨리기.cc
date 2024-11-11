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

using namespace std;

deque<pair<int, int>> dq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        dq.push_back(make_pair(i + 1, tmp));
    }
    while (!dq.empty())
    {
        tmp = dq.front().second;

        cout << dq.front().first << ' ';
        dq.pop_front();

        if (dq.size() == 1)
        {
            cout << dq.front().first;
            dq.pop_front();
            break;
        }
        if (tmp > 0)
        {
            for (int i = 0; i < tmp - 1; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else
        {
            for (int i = 0; i < -1 * tmp; i++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}
