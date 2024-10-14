#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

vector<int> calculate(int n){
    vector<int> v{25,10,5,1};
    vector<int> ans(4);

    for(int i = 0;i<4;i++){
        ans[i] = n/v[i];
        n -= ans[i] * v[i];
    }

    return ans;
}

int main()
{
    int n;
    int total;
    vector<int> v(4);
    cin >> n;

    for(int i =0;i<n;i++){
        cin >> total;
        for(int j : calculate(total)){
            cout<< j << ' ';
        }
        cout<< '\n';
    }
    return 0;
}