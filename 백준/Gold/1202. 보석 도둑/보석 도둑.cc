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
#define MAX 300001

using namespace std;

priority_queue<int> pq;
int bag[MAX];
pair<int, int> jew[MAX];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int tmpM, tmpV;
    int tmpC;
    for (int i = 0; i < n; i++)
    {
        cin >> tmpM >> tmpV;
        jew[i] = make_pair(tmpM, tmpV);
    }

    for (int i = 0; i < k; i++)
    {
        cin >> bag[i];
    }

    sort(jew, jew + n);
    sort(bag, bag + k);

    int flag = 0;
    long long answer = 0;
    for (int i = 0; i < k; i++)
    {
        while (flag < n && bag[i] >= jew[flag].first)
        {
            pq.push(jew[flag].second);
            flag++;
        }
        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }
    cout << answer;

    return 0;
}