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
#include <numeric>
#define endl '\n'
#define MAX INT32_MAX

using namespace std;

int fruit[10];

int getCount()
{
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        if (fruit[i] != 0)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    for (int i = 0; i < 10; i++)
    {
        fruit[i] = 0;
    }

    int start = 0;
    int end = 0;
    int answer = 1;

    fruit[v[end]]++;

    while (start < n)
    {
        while (end < n)
        {
            end++;
            if (end >= n)
            {
                break;
            }
            fruit[v[end]]++;
            if (getCount() > 2)
            {
                fruit[v[end]]--;
                end--;
                answer = max(answer, end - start + 1);
                break;
            }
            else
            {
                answer = max(answer, end - start + 1);
            }
        }
        fruit[v[start]]--;
        start++;
    }
    cout << answer;
    return 0;
}