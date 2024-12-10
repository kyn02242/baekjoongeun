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

int l, c;
vector<char> characterSet;
vector<char> stringSet;
bool visited[16];

bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    return false;
}

int countVowelNumber(string str)
{
    int cnt = 0;
    for (int i = 0; i < l; i++)
    {
        if (isVowel(str[i]))
        {
            cnt++;
        }
    }
    return cnt;
}

int countVowelNumber(vector<char> stringSet)
{
    int cnt = 0;
    for (int i = 0; i < l; i++)
    {
        if (isVowel(stringSet[i]))
        {
            cnt++;
        }
    }
    return cnt;
}

void DFS(int index)
{
    if (stringSet.size() == l)
    {
        int n = countVowelNumber(stringSet);
        if (n >= 1 && l - n >= 2)
        {
            for (char i : stringSet)
            {
                cout << i;
            }
            cout << endl;
            return;
        }
    }

    for (int i = index; i < characterSet.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            stringSet.push_back(characterSet[i]);
            DFS(i + 1);
            stringSet.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> l >> c;

    char tmp;

    for (int i = 0; i < c; i++)
    {
        cin >> tmp;
        characterSet.push_back(tmp);
    }

    sort(characterSet.begin(), characterSet.end());

    DFS(0);

    return 0;
}