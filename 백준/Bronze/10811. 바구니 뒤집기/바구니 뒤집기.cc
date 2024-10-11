#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        v[i] = i + 1;
    }

    int s, e;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        s -= 1;
        reverse(v.begin() + s, v.begin() + e);
    }

    for (int i : v)
    {
        cout << i << ' ';
    }
    return 0;
}