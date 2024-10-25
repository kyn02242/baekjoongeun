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

    long long a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << a << endl;
        return 0;
    }

    if (a < b) // 계산에 유리하도록 a에 큰 수
    {
        long long tmp = a;
        a = b;
        b = tmp;
    }
    for (long long j = 1; j <= b; j++)
    {
        if (a * j % b == 0)
        {
            cout << a * j << endl;
            break;
        }
    }

    return 0;
}