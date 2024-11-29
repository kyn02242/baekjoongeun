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

priority_queue<int> q;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a;
    cin >> a;
    long long answer = 1;
    for (int i = 1; i <= a; i++)
    {
        answer *= i;
    }
    cout << answer;

    return 0;
}