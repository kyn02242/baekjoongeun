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

string isCorrect(string str)
{
    regex pattern("(100+1+|01)+");
    return regex_match(str, pattern) ? "YES" : "NO";
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        cout << isCorrect(str) << endl;
    }

    return 0;
}