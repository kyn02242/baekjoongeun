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
#include <regex>
#define endl '\n'
#define ll long long int

using namespace std;
vector<ll> v;

ll findDecreasing(int n)
{
    queue<ll> q;
    for (int i = 0; i < 10; i++)
    {
        q.push(i);
        v.push_back(i);
    }
    while (!q.empty())
    {
        ll num = q.front();
        int last = num % 10;
        q.pop();
        for (int i = 0; i < last; i++)
        {
            ll nextN = num * 10 + i;
            q.push(nextN);
            v.push_back(nextN);
        }
    }

    if (n >= v.size())
    {
        return -1;
    }
    return v[n];
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << findDecreasing(n);
    return 0;
}