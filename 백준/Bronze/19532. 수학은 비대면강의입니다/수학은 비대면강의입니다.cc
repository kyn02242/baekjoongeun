#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    for(int i=-999;i<1000;i++){
        for(int j=-999;j<1000;j++){
            if(a*i+b*j-c==d*i+e*j-f && a*i+b*j-c == 0){
                cout<<i<<' '<<j;
                return 0;
            }
        }
    }
}