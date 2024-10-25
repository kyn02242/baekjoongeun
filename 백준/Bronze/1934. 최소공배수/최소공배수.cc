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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    int a, b;

    for (int i = 0; i < T; i++)
    {
        cin >> a >> b;
        if (a == b)
        {
            cout << a << endl;
            continue;
        }

        if (a < b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }

        for (int j = 1;; j++)
        {
            if (a * j % b == 0)
            {
                cout << a * j << endl;
                break;
            }
        }
    }

    return 0;
}