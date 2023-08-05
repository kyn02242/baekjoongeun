#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <sstream>
#include <memory>
#include <deque>

using namespace std;

int main()
{
    int test;
    int m, n, x, y;
    cin >> test;
    for (int j = 0; j < test; j++)
    {
        cin >> m >> n >> x >> y;
        int ans = -1;

        for (int i = 0; i < 40001; i++)
        {
            if ((i * n + y - x) % m == 0)
            {
                ans = i * n + y;
                break;
            }
        }
        cout << ans << endl;
        ;
    }

    return 0;
}