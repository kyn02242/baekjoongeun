#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    int cnt = 0;
    cin >> a >> b;
    while (1) {
        if (a>=b) {
            break;
        }
        if (b % 10 == 1) {
            cnt++;
            b = b / 10;
        }
        else if (b % 2 == 0) {
            cnt++;
            b = b / 2;
        }
        else {
            break;
        }
    }
    if (a == b) {
        cout << cnt+1 << endl;
    }
    else {
        cout << "-1" << endl;
    }

}
