#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int main()
{
    int n, k;
    int flag = 0;
    cin >> n >> k;

    if (k == 1)
    {
        cout << 1;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if(n%i == 0){
            flag ++;
        }

        if(flag == k){
            cout<<i;
            return 0;
        }
    }

    cout << 0;
    return 0;
}
