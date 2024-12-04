#include <string>
#include <string.h>
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
#include <numeric>
#define endl '\n'
#define LINE cout << endl
#define MAX 300001

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    bool alpha[26];

    string str;
    int cnt;

    while (true)
    {
        getline(cin, str);

        if (str == "#")
        {
            break;
        }

        cnt = 0;

        memset(alpha, false, sizeof(alpha));

        for (auto i : str)
        {
            // cout << "i : " << i << ' ';
            if (i >= 'a' && i <= 'z')
            {
                if (alpha[i - 'a'] == false)
                {
                    alpha[i - 'a'] = true;
                    cnt++;
                }
            }
            else if (i >= 'A' && i <= 'Z')
            {
                if (alpha[i - 'A'] == false)
                {
                    alpha[i - 'A'] = true;
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}