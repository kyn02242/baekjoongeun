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
    int x,y;
    vector<vector<int>> v(4, vector<int>(2));
    for(int i =0 ;i<3;i++){
        cin >>v[i][0] >> v[i][1];
    }
    if(v[0][0] == v[1][0]){
        x = v[2][0];
    }
    else if(v[0][0] == v[2][0]){
        x = v[1][0];
    }
    else{
        x = v[0][0];
    }

    if(v[0][1] == v[1][1]){
        y = v[2][1];
    }
    else if(v[0][1] == v[2][1]){
        y = v[1][1];
    }
    else{
        y = v[0][1];
    }

    cout << x << ' ' << y;
    return 0;
}
