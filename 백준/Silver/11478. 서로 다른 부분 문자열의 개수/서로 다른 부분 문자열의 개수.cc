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
#define endl '\n'

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string l;
    cin >> l;
    string tmp;
    unordered_set<string> st;

    for (int i = 0; i < l.size(); i++)
    {
        for (int j = 1; j <= l.size(); j++)
        {
            tmp = l.substr(i, j);
            st.insert(tmp);
        }
    }
    
    cout << st.size();

    return 0;
}