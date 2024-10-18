#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

string calculate(int n)
{
    string ans = to_string(n) + " = ";
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            ans += to_string(i);
            if (sum < n)
            {
                ans += " + ";
            }
        }
    }

    if (sum != n)
    {
        ans = to_string(n) + " is NOT perfect.";
    }

    return ans;
}

int main()
{
    int n;
    while (1)
    {
        cin >> n;
        if (n == -1)
        {
            break;
        }
        cout << calculate(n) << '\n';
    }
    return 0;
}
