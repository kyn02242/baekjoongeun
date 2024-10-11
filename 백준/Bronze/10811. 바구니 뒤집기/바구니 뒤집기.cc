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
        e -= 1;
        vector<int> v1(e - s + 1);
        for (int j = 0; j < e - s + 1; j++)
        {
            v1[j] = v[e - j];
        }
        for (int j = 0; j < e - s + 1; j++)
        {
            v[s + j] = v1[j];
        }
    }

    for(int i = 0; i < m; i++){
        cout << v[i] << ' ';
    }
    return 0;
}