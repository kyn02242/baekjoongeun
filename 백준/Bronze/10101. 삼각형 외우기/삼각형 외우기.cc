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
    vector<int> v(3);
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());

    if (sum != 180)
    {
        cout << "Error";
        return 0;
    }

    if (v[0] != v[1] && v[1] != v[2])
    {
        cout << "Scalene";
        return 0;
    }

    if (v[0] == v[1] && v[0] == 60)
    {
        cout << "Equilateral";
    }
    else
    {
        cout << "Isosceles";
    }
    return 0;
}
