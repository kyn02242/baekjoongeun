#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#define endl '\n'

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a,b;
    cin>> a>>b;
    int sum = a+b;
    int tmp;
    unordered_set<int> st;

    for(int i = 0;i<a;i++){
        cin>>tmp;
        st.insert(tmp);
    }
    for(int i=0;i<b;i++){
        cin>>tmp;
        if(st.find(tmp)!=st.end()){
            st.erase(tmp);
        }
        else{
            st.insert(tmp);
        }
    }

    cout<<st.size();

    return 0;
}