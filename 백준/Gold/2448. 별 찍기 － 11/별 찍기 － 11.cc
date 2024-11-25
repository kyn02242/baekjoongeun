#include <string>
#include <string.h>
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
#include <numeric>
#define endl '\n'
#define LINE cout << endl
#define MAX INT32_MAX

using namespace std;

char star[3072][6144]; // 3*2^10, 3*2^10 * 2 - 1

void printStar(int x, int y, int n)
{
    if (n == 3)
    {
        star[x][y] = '*';
        star[x + 1][y - 1] = '*';
        star[x + 2][y - 2] = '*';
        star[x + 2][y - 1] = '*';
        star[x + 2][y] = '*';
        star[x + 2][y + 1] = '*';
        star[x + 2][y + 2] = '*';
        star[x + 1][y + 1] = '*';
    }
    else
    {
        printStar(x, y, n / 2);
        printStar(x + n / 2, y - n / 2, n / 2);
        printStar(x + n / 2, y + n / 2, n / 2);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int m = 2 * n - 1;
    memset(star, ' ', sizeof(star));

    printStar(0, n - 1, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << star[i][j];
        }
        cout << endl;
    }

    return 0;
}