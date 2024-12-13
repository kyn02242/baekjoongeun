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
#include <regex>
#define endl '\n'
#define ll long long int

using namespace std;

int n, k, root;
int leaf = 0;
vector<int> v[51];

int DFS(int node)
{
    if (node == k)
    {
        return -1;
    }
    if (!v[node].size())
    {
        leaf++;
        return 0;
    }
    for (int i = 0; i < v[node].size(); i++)
    {
        int tmp = DFS(v[node][i]);
        if (tmp == -1 && v[node].size() == 1)
        {
            leaf++;
        }
    }
    return 0;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp == -1)
            root = i;
        else
            v[tmp].push_back(i);
    }
    cin >> k;

    DFS(root);

    cout << leaf;

    return 0;
}