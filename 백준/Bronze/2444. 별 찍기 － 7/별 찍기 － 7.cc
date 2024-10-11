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
    cin >> n;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (i < n)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                cout << ' ';
            }
            for (int j = 0; j < i * 2 + 1; j++)
            {
                cout << '*';
            }
        }
        else{
            for (int j = 0; j < i - n + 1; j++)
            {
                cout << ' ';
            }
            for (int j = 0; j < 2 * (2 * n - i - 1) - 1; j++)
            {
                cout << '*';
            }
        }
        cout << '\n';
    }
    return 0;
}