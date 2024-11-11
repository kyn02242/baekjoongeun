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

int main()
{
    cin.tie(NULL);
    int num;
    cin >> num;
    int op;
    int size = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            st.push(x);
            size++;
        }
        else if (op == 2)
        {
            if (size > 0)
            {
                cout << st.top() << endl;
                st.pop();
                size--;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (op == 3)
        {
            cout << size << endl;
        }
        else if (op == 4)
        {
            cout << (size == 0) << endl;
        }
        else if (op == 5)
        {
            if (size > 0)
            {
                cout << st.top() << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}