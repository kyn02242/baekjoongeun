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
#define ALL 1000003

using namespace std;

vector<bool> vAll(ALL, true);

void check()
{
    vAll[0] = false;
    vAll[1] = false;

    for (int i = 2; i < ALL; i++)
    {
        if (vAll[i])
        {
            for (int j = i * 2; j < ALL; j += i)
            {
                vAll[j] = false;
            }
        }
    }
}

int main()
{
    check();
    int t;
    cin >> t;
    int n;
    int cnt;
    for (int i = 0; i < t; i++)
    {
        cnt = 0;
        cin >> n;
        for (int j = 2; j <= n / 2; j++)
        {
            if (vAll[j] && vAll[n - j])
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
