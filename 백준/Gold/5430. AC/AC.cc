#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <sstream>
#include <memory>
#include <deque>

using namespace std;

queue<char> q;
int R = 0;
string func;
deque<int> dq;

int getnumarr(int num)
{
    char tmp;
    int sum = 0;
    for (int i = 0; tmp != ']'; i++)
    {
        cin >> tmp;
        if (tmp >= '0' && tmp <= '9')
        {
            if (sum != 0)
            {
                sum *= 10;
            }
            sum += (tmp - '0');
        }
        else
        {
            if (sum != 0)
            {
                dq.push_back(sum);
                sum = 0;
            }
        }
    }
    if (dq.size() != num)
    {
        cout << "error" << endl;
        return -1;
    }
    return 0;
}
void getarr()
{
    cout << '[';
    if (R == 0)
    {
        while (!dq.empty())
        {
            cout << dq.front();
            dq.pop_front();
            if (!dq.empty())
            {
                cout << ',';
            }
        }
    }
    else
    {
        while (!dq.empty())
        {
            cout << dq.back();
            dq.pop_back();
            if (!dq.empty())
            {
                cout << ',';
            }
        }
    }
    cout << ']' << endl;
}

int operate()
{

    while (!q.empty())
    {
        char tmp = q.front();
        q.pop();
        if (tmp == 'R')
        {
            if (R == 0)
            {
                R = 1;
            }
            else if (R == 1)
            {
                R = 0;
            }
        }
        if (tmp == 'D')
        {
            if (dq.empty())
            {
                cout << "error" << endl;
                return -1;
            }
            if (R == 0)
            {
                dq.pop_front();
            }
            else if (R == 1)
            {
                dq.pop_back();
            }
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;

    int num;

    for (int i = 0; i < n; i++)
    {
        while (!q.empty())
            q.pop();

        int check = 0;
        R = 0;

        cin >> func;

        for (int j = 0; j < func.length(); j++)
        {
            q.push(func[j]);
        }
        cin >> num;

        check = getnumarr(num);

        if (check == -1)
        {
            continue;
        }

        check = operate();

        if (check == -1)
        {
            continue;
        }

        getarr();
    }

    return 0;
}