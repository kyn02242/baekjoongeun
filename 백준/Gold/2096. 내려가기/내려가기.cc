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
#define LINE cout << endl
#define MAX INT32_MAX

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int maxArr[3] = {0, 0, 0};
    int minArr[3] = {0, 0, 0};
    int arr[3];
    cin >> maxArr[0] >> maxArr[1] >> maxArr[2];
    minArr[0] = maxArr[0];
    minArr[1] = maxArr[1];
    minArr[2] = maxArr[2];

    int tmp, ttmp;
    for (int i = 1; i < n; i++)
    {
        cin >> arr[0] >> arr[1] >> arr[2];

        // 최댓값
        tmp = maxArr[0];
        ttmp = maxArr[2];
        maxArr[0] = max(maxArr[0], maxArr[1]) + arr[0];
        maxArr[2] = max(maxArr[1], maxArr[2]) + arr[2];
        maxArr[1] = max(max(tmp, maxArr[1]), ttmp) + arr[1];

        // 최솟값
        tmp = minArr[0];
        ttmp = minArr[2];
        minArr[0] = min(minArr[0], minArr[1]) + arr[0];
        minArr[2] = min(minArr[1], minArr[2]) + arr[2];
        minArr[1] = min(min(tmp, minArr[1]), ttmp) + arr[1];
    }

    cout << max(max(maxArr[0], maxArr[1]), maxArr[2]) << ' ' << min(min(minArr[0], minArr[1]), minArr[2]);

    return 0;
}