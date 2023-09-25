#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    vector<int> dp(sticker.size());
    int n = sticker.size();
    if(n==1){
        answer = sticker[0];
        return answer;
    }
    dp[0] = sticker[0];
    dp[1] = dp[0];
    for(int i=2;i<n;i++){//0번 사용
        dp[i] = max(dp[i-1],dp[i-2]+sticker[i]);
    }
    dp[n-1] = dp[n-2];//마지막 값은 첫 값을 사용함으로 사라졌기 때문에
    int maxtmp = 0;
    for(int i=0;i<n;i++){
        if(maxtmp<dp[i]){
            maxtmp = dp[i];
        }
    }
    dp[0] = 0;
    dp[1] = sticker[1];
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1],dp[i-2] + sticker[i]);//첫값 사용하지 않음(dp[0] = 0)
    }
    for(int i=0;i<n;i++){
        if(maxtmp<dp[i]){
            maxtmp = dp[i];
        }
    }
    answer = maxtmp;
    
    return answer;
}