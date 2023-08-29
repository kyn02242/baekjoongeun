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
#include <stack>
#include <cstring>
#define endl '\n'
#define INTMAX 2147483647
#define LONGLONGMAX 9223372036854775807
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string s;
    stack<char> operation;

    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            cout << s[i];
        }
        else
        {
            if (s[i] == '(')
                operation.push(s[i]);
            else if (s[i] == '*' || s[i] == '/')
            {
                while (!operation.empty() && (operation.top() == '*' || operation.top() == '/'))
                {
                    cout << operation.top();
                    operation.pop();
                }
                operation.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                while (!operation.empty() && operation.top() != '(')
                {
                    cout << operation.top();
                    operation.pop();
                }
                operation.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!operation.empty() && operation.top() != '(')
                {
                    cout << operation.top();
                    operation.pop();
                }
                operation.pop();
            }
        }
    }
    while (!operation.empty())
    {
        cout << operation.top();
        operation.pop();
    }

    return 0;
}