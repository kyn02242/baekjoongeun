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
    int n;
    int a, b;
    int ans = 0;
    vector<vector<int>> v(100, vector<int>(100, 0));
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                v[j + a][k + b] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            ans += v[i][j];
        }
    }

    cout << ans;

    return 0;
}