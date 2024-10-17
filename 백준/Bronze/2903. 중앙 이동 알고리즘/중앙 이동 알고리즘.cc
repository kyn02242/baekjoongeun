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
    int n;
    cin >> n;
    long long ans = pow(pow(2, n) + 1, 2);
    cout << ans;
    return 0;
}
