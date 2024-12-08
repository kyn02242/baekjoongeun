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

using namespace std;

set<long long int> PowList;
bool check[10];
int n, m;

bool isMakeable(int n)
{
    string str = to_string(n);
    for (int i = 0; i < str.length(); i++)
    {
        if (!check[str[i] - '0'])
        {
            return false;
        }
    }
    return true;
}

void findPow()
{
    long long int tmp;
    for (int i = 0;; i++)
    {
        tmp = pow(i, 2);
        if (tmp <= pow(10, max(n, m)))
        {
            if (isMakeable(tmp))
            {
                PowList.insert(tmp);
            }
        }
        else
        {
            break;
        }
    }
}

int DFS(pair<int, int> lastIndex, int diffI, int diffJ, vector<vector<pair<int, int>>> tmpV, int stack)
{
    if (stack == tmpV.size())
    {
        return stack;
    }

    for (int i = 0; i < tmpV[stack].size(); i++)
    {
        int tmpDiffI = lastIndex.first - tmpV[stack][i].first;
        int tmpDiffJ = lastIndex.second - tmpV[stack][i].second;

        if (diffI == tmpDiffI && tmpDiffJ == diffJ)
        {
            return DFS(tmpV[stack][i], diffI, diffJ, tmpV, stack + 1);
        }
    }
    return stack;
}

bool isAnswer(int N, vector<vector<int>> v)
{
    // 두자리 수는 무조건 가능
    if (N < 100)
    {
        return true;
    }

    // 세자리부터는 확인 필요
    string str = to_string(N);
    int len = str.length();
    vector<vector<pair<int, int>>> tmpV(len, vector<pair<int, int>>());

    // i,j 전체 저장
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (v[j][k] + '0' == str[i])
                {
                    tmpV[i].push_back(make_pair(j, k));
                }
            }
        }
    }

    // (i,j)가 등차수열인것 찾기
    // DFS를 끝까지 통과한 것 유무 확인(?)
    for (int i = 0; i < tmpV[0].size(); i++)
    {
        for (int j = 0; j < tmpV[1].size(); j++)
        {
            int diffI = tmpV[0][i].first - tmpV[1][j].first;
            int diffJ = tmpV[0][i].second - tmpV[1][j].second;
            if (DFS(tmpV[1][j], diffI, diffJ, tmpV, 2) == len)
            {
                return true;
            }
        }
    }

    // 없으면 false 반환
    return false;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));

    char tmp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tmp;
            v[i][j] = tmp - '0';
            check[v[i][j]] = true;
        }
    }

    findPow();

    for (auto i = PowList.rbegin(); i != PowList.rend(); i++)
    {
        if (isAnswer(*i, v))
        {
            cout << *i;
            return 0;
        }
    }

    cout << -1;

    return 0;
}