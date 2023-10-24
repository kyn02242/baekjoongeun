#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int n = numbers.size();
    vector<int> v(pow(2,n));
    for(int i=0;i<n;i++){
        int flag = pow(2,n)/pow(2,i+1);
        int cnt = 0;
        bool oper = true;
        for(int j=0;j<pow(2,n);j++){
            if(oper){
                v[j]+=numbers[i];
                cnt++;
            }
            else{
                v[j]-=numbers[i];
                cnt++;
            }
            if(cnt==flag){
                oper = !oper;
                cnt = 0;
            }
        }
    }
    for(auto i : v){
        if(i==target){
            answer++;
        }
        //cout<<i<<endl;
    }
    return answer;
}