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
    string l;
    cin >> l;
    int s, e;
    s = 0;
    e = l.length() - 1;
    while (s < e)
    {
        if (l[s] != l[e])
        {
            cout << 0;
            return 0;
        }
        s++;
        e--;
    }
    cout << 1;
    return 0;
}