#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    map<int,bool> mp;
    for(int i=0;i<elements.size();i++){
        for(int j=1;j<=elements.size();j++){
            int sum = 0;
            for(int k=0;k<j;k++){
                int n = i+k;
                if(i+k>=elements.size()){
                    n-=elements.size();
                }
                sum+=elements[n];
            }
            mp[sum] = true;
            // cout<<"i : "<<i<< ", j : "<<j<<", sum : "<<sum<<endl;
        }
    }
    // for(auto i : mp){
    //     cout<<i.first<<endl;
    // }
    answer = mp.size();
    
    return answer;
}