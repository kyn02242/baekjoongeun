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
    string str;
    int n;
    int ans = 0;
    int flag = 0;
    cin >> str >> n;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        int tmp;
        if(str[i] >= 'A' && str[i] <= 'Z'){
            tmp = str[i] - 'A' + 10;
        }
        else{
            tmp = str[i] - '0';
        }
        ans += pow(n, flag) * tmp;
        flag++;
    }

    cout << ans;
    return 0;
}