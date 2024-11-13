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

    int n;
    cin >> n;
    vector<int> v(n);
    int battery = 2;
    int last = 2;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i < n; i++)
    {
        if(v[i-1] == v[i]){
            last *= 2;
            if(last == 0){
                last = 2;
            }
        }
        else{
            last = 2;
        }
        battery += last;

        if(battery >= 100){
            battery = 0;
            last = 0;
        }
    }

    cout << battery;

    return 0;
}