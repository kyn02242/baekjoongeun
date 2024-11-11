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
#define OO " "

using namespace std;

void printing(string str)
{
    int len = str.length();
    cout << str << endl;
    if (len != 1)
    {
        for (int i = 0; i < len - 2; i++)
        {
            cout << str[i + 1];
            for (int j = 0; j < len - 2; j++)
            {
                cout << OO;
            }
            cout << str[len - 2 - i] << endl;
        }
        reverse(str.begin(), str.end());
        cout << str << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        printing(tmp);
    }

    return 0;
}
