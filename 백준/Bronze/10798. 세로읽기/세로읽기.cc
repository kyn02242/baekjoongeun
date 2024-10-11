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
    vector<string> v(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> v[i];
        v[i].resize(15, ' ');
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (v[j][i] != ' ')
            {
                cout << v[j][i];
            }
        }
    }
    return 0;
}