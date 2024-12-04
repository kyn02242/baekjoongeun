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

int n;
int date[16];
int value[16];
int cal[16];

void dp()
{
    int limit;
    for (int i = n; i > 0; i--)
    {
        limit = i + date[i];
        if (limit > n + 1)
        {
            cal[i] = cal[i + 1];
        }
        else
        {
            cal[i] = max(cal[i + 1], cal[limit] + value[i]);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> date[i] >> value[i];
    }

    dp();

    cout << cal[1];

    return 0;
}