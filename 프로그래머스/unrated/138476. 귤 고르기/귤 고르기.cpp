#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> v(10000001);
    for(int i=0;i<tangerine.size();i++){
        v[tangerine[i]]++;
        if(v[tangerine[i]]==k){
            return 1;
        }
    }
    sort(v.rbegin(),v.rend());
    int cnt = 0;
    for(int i=0;i<=k;i++){
        cnt += v[i];
        answer++;
        if(cnt>=k){
            return answer;
        }
    }
    
    return answer;
}