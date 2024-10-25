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

using namespace std;

int main()
{
    int n, m;
    int answer = 0;
    unordered_set<string> st;
    string tmp;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        st.insert(tmp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        if (st.find(tmp) != st.end())
        {
            answer++;
        }
    }
    cout << answer;
    return 0;
}