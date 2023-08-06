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
#include<set>

using namespace std;

int main()
{
    int testcase;
    int oper;
    char tmp_op;
    int tmp_num;
    int flag = 0;

    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {   multiset<int> ms;
        cin >> oper;
        for (int j = 0; j < oper; j++)
        {
            cin >> tmp_op>>tmp_num;
            if (tmp_op == 'I')
            {
                ms.insert(tmp_num);
            }
            else
            {
                if (!ms.empty() && tmp_num == -1)
                {
                    ms.erase(ms.begin());
                }
                else if (!ms.empty() && tmp_num == 1)
                {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                }
            }
        }
        if (ms.empty())
        {
            cout << "EMPTY" << endl;
        }
        else
        {
            auto end_iter = ms.end();
            end_iter--;
            cout << *end_iter << ' ' << *ms.begin() << endl;
        }
    }
    return 0;
}