#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#define endl '\n'

using namespace std;

int Find(int a, int b)
{
    if (a == b)
        return a;

    if (a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    for (int i = 1; i <= a; i++)
    {
        if ((b * i) % a == 0)
        {
            return b * i;
        }
    }
}

int FindLow(int a, int b)
{
    if (a == b)
        return a;

    if (a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    for (int i = b; i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int u1, u2;
    int b1, b2;

    cin >> u1 >> b1;
    cin >> u2 >> b2;

    int ansb = Find(b1, b2);
    int ansu = u1 * (ansb / b1) + u2 * (ansb / b2);

    int k = FindLow(ansu, ansb);
    cout << ansu / k << ' ' << ansb / k;

    return 0;
}