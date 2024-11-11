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
#define endl '\n'

using namespace std;

stack<int> st;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string op;
    int n;
    cin >> n;
    int size = 0;
    int tmpNum;
    for (int i = 0; i < n; i++)
    {
        cin >> op;
        if (op == "push")
        {
            cin >> tmpNum;
            q.push(tmpNum);
            size++;
        }
        else if (op == "empty")
        {
            cout << (size == 0) << endl;
        }
        else if (op == "size")
        {
            cout << size << endl;
        }
        else
        {
            if (size == 0)
            {
                cout << -1 << endl;
                continue;
            }
            if (op == "pop")
            {
                cout << q.front() << endl;
                q.pop();
                size--;
            }
            if (op == "front")
            {
                cout << q.front() << endl;
            }
            if (op == "back")
            {
                cout << q.back() << endl;
            }
        }
    }

    return 0;
}