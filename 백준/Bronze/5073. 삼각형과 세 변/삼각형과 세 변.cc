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
    while (1)
    {
        sum = 0;

        for (int i = 0; i < 3; i++)
        {
            cin >> v[i];
            sum += v[i];
        }

        if (sum == 0){
            break;
        }

        sort(v.begin(), v.end());

        if (v[2] >= v[0] + v[1])
        {
            cout << "Invalid" << '\n';
            continue;
        }

        if (v[0] == v[2])
        {
            cout << "Equilateral" << '\n';
        }
        else if (v[0] == v[1] || v[1] == v[2])
        {
            cout << "Isosceles" << '\n';
        }
        else
        {
            cout << "Scalene" << '\n';
        }
    }
}
