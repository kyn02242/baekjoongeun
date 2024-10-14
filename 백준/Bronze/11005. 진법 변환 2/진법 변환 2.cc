#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

char convert(int n){
    char res;
    if (n >= 10){
        res = 'A' + n - 10;
    }
    else{
        res = '0' + n;
    }

    return res;
}

int main()
{
    int n;
    int p;
    string str;
    cin >> n >> p;

    while(n>0){
        str.push_back(convert(n%p));
        n /= p;
    }

    reverse(str.begin(),str.end());
    cout << str;
    
    return 0;
}