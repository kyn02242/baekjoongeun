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
    int sum = 0;
    vector<int> v(5);
    for(int i = 0; i<5;i++){
        cin>>v[i];
        sum += v[i];
    }
    sort(v.begin(),v.end());
    cout<<sum/5<<endl<<v[2];
    return 0;
}