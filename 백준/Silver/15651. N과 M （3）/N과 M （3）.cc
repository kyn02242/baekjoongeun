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
#define MAX 300001

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int m, n;

    cin >> n >> m;

    vector<int> v(m, 1);
    while (1)
    {
        for (auto i : v)
        {
            cout << i << ' ';
        }
        cout << endl;

        v[m - 1]++;

        for (int i = m - 1; i > 0; i--)
        {
            if (v[i] > n)
            {
                v[i - 1]++;
                v[i] = 1;
            }
        }

        if (v[0] > n)
        {
            break;
        }
    }

    return 0;
}