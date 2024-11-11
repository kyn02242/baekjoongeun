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
#include <deque>
#define endl '\n'

using namespace std;

deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int op;
    int n;
    cin >> n;
    int size = 0;
    int tmpNum;
    for (int i = 0; i < n; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> tmpNum;
            dq.push_front(tmpNum);
            size++;
        }
        else if (op == 2)
        {
            cin >> tmpNum;
            dq.push_back(tmpNum);
            size++;
        }
        else if (op == 6)
        {
            cout << (size == 0) << endl;
        }
        else if (op == 5)
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
            else if (op == 3)
            {
                cout << dq.front() << endl;
                dq.pop_front();
                size--;
            }
            else if (op == 4)
            {
                cout << dq.back() << endl;
                dq.pop_back();
                size--;
            }
            else if (op == 7)
            {
                cout << dq.front() << endl;
            }
            else if (op == 8)
            {
                cout << dq.back() << endl;
            }
        }
    }

    return 0;
}