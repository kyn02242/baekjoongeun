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
#define MAX INT_MAX

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    int tmp;
    bool esc = false;

    while (1)
    {
        cin >> num;
        if (num == 0)
            break;

        int count = 0;
        int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        bool esc = false;

        for (int i = 1; i < 10; i++)
        {
            if (esc)
            {
                cout << endl;
                break;
            }
            do
            {
                if (arr[0] != 0)
                {
                    count++;
                    // for (int j = 0; j < i; j++)
                    // {
                    //     cout << arr[j];
                    // }
                    // cout << endl;
                }
                if (count == num)
                {
                    for (int j = 0; j < i; j++)
                    {
                        cout << arr[j];
                    }
                    esc = true;
                    break;
                }
                reverse(arr + i, arr + 10);
            } while (next_permutation(arr, arr + 10));
        }
    }

    return 0;
}