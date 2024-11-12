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
#define MAX 100
using namespace std;

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(6);
    for (int i = 0; i < 6; i++)
    {
        cin >> v[i];
    }
    int t, p;
    cin >> t >> p;

    int sumTshirt = 0;

    for (auto i : v)
    {
        sumTshirt += i / t;
        if (i % t != 0)
        {
            sumTshirt++;
        }
    }

    cout << sumTshirt << endl;

    cout << n / p << ' ' << n % p;

    return 0;
}
