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
#include <stack>
#include <deque>
#define endl '\n'
#define MAX INT_MAX

using namespace std;

int factorial(int n)
{
    int ret = 1;
    for (int i = 1; i <= n; i++)
    {
        ret *= i;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    while (1)
    {
        cin >> a >> b;
        if (a == b && a == -1)
        {
            break;
        }

        if (factorial(a + b) / (factorial(a) * factorial(b)) == a + b)
        {
            cout << a << '+' << b << '=' << a + b << endl;
        }
        else
        {
            cout << a << '+' << b << "!=" << a + b << endl;
        }
    }

    return 0;
}
