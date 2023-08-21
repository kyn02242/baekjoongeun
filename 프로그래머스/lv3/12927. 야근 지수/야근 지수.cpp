#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long sum = 0;
    for(int i=0;i<works.size();i++){
        sum+=works[i];
    }
    if(sum<=n){
        answer = 0;
        return answer;
    }
    int flag=0;
    sort(works.rbegin(),works.rend());
    while(n>0){
        if(works[flag]<works[flag+1]){
            flag++;
            works[flag]--;
            n--;
        }
        else{
            flag = 0;
            while(works[flag]<works[flag+1]){
                flag++;
            }
            works[flag]--;
            n--;
        }
        
    }
    for(int i=0;i<works.size();i++){
        answer+=pow(works[i],2);
    }
    
    
    return answer;
}