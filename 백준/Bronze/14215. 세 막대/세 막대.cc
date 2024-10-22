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
    vector<int> v(3);
    for(int i = 0;i<3;i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    if(v[2] >= v[0]+ v[1]){
        v[2] = v[0]+ v[1] - 1;
    }

    cout << v[0] + v[1] + v[2];

    return 0;
}
