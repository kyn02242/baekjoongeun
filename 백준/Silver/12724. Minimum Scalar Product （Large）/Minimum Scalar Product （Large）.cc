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

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    int n;

    for (int i = 0; i < T; i++)
    {
        cin >> n;
        vector<long long> v1(n);
        vector<long long> v2(n);
        long long total = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> v1[j];
        }
        for (int j = 0; j < n; j++)
        {
            cin >> v2[j];
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), compare);

        for (int j = 0; j < n; j++)
        {
            total += v1[j] * v2[j];
        }
        cout << "Case #" << i + 1 << ": " << total << endl;
    }

    return 0;
}