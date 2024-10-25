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

struct Compare
{
    bool operator()(const string &a, const string &b) const
    {
        return a > b;
    }
};

set<string, Compare> st;

void Leave(string name)
{
    // if (st.find(name) == st.end())
    // {
    //     cout << "ERROR" << endl;
    //     return;
    // }
    st.erase(name);
    return;
}

void Enter(string name)
{
    // if (st.find(name) != st.end())
    // {
    //     cout << "ERROR" << endl;
    //     return;
    // }
    st.insert(name);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string tmp;
    string cmd;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp >> cmd;
        if (cmd == "enter")
            Enter(tmp);
        if (cmd == "leave")
            Leave(tmp);
    }

    for (auto name : st)
    {
        cout << name << endl;
    }

    return 0;
}