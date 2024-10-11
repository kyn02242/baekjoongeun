#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int main(){
    int n;
    int a,b;
    cin >> n;
    a = n * 78 / 100;
    b = (n * 8 / 10) + (n * 2 / 10 * 78 / 100);

    cout << a << ' ' << b;

    return 0;
}