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

deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int tmp;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (v[i] == 0)
        {
            dq.push_front(tmp);
        }
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        dq.push_back(tmp);
    }

    for (int i = 0; i < n; i++)
    {
        cout << dq.front() << ' ';
        dq.pop_front();
    }

    return 0;
}
