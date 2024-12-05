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

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string origin;
    cin >> origin;
    int originSize = origin.length();
    string tmp;

    vector<string> v;
    for (int i = 0; i < originSize - 2; i++)
    {
        for (int j = i + 1; j < originSize - 1; j++)
        {
            for (int k = j + 1; k < originSize; k++)
            {
                tmp = origin;
                reverse(tmp.begin() + i, tmp.begin() + j);
                reverse(tmp.begin() + j, tmp.begin() + k);
                reverse(tmp.begin() + k, tmp.end());
                v.push_back(tmp);
            }
        }
    }

    sort(v.begin(), v.end());

    if (origin == v[0] && originSize!=3)
    {
        cout << v[1];
    }
    else
    {
        cout << v[0];
    }

    return 0;
}