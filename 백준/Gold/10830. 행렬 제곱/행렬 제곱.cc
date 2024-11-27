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

int availNumber(int a)
{
    return a % 1000;
}

void calculate(vector<vector<int>> &A, vector<vector<int>> &B, int n)
{
    vector<vector<int>> tmp(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = 0;
            for (int x = 0; x < n; x++)
            {
                tmp[i][j] += A[i][x] * B[x][j];
            }

            tmp[i][j] = availNumber(tmp[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = tmp[i][j];
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    long long b;

    cin >> n >> b;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
            if (i == j)
            {
                result[i][j] = 1;
            }
            else
            {
                result[i][j] = 0;
            }
        }
    }

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            calculate(result, A, n);
        }
        calculate(A, A, n);
        b /= 2;
    }

    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        LINE;
    }

    return 0;
}