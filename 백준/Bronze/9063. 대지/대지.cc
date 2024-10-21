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
    int x,y;
    int mxx = -10000, mnx = 10000;
    int mxy = -10000, mny = 10000;
    cin >> n;
    for(int i = 0; i< n;i++){
        cin >> x >> y;
        mxx = max(mxx,x);
        mnx = min(mnx,x);
        mxy = max(mxy,y);
        mny = min(mny,y);
    }

    cout << (mxx - mnx) * (mxy - mny);

    return 0;
}
