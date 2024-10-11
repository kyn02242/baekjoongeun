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
    vector<vector<int>> v(9, vector<int>(9));

    int max = 0;
    int tmpi = 0, tmpj = 0;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> v[i][j];
            if (v[i][j] > max)
            {
                max = v[i][j];
                tmpi = i;
                tmpj = j;
            }
        }
    }
    cout << max << '\n'
         << tmpi + 1 << ' ' << tmpj + 1;
    return 0;
}