#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int cnt1 = 0;
    int cnt2 = 1;
    
    for(int i=0;i<num_list.size();i++){
        cnt1 += num_list[i];
        cnt2 *= num_list[i];
    }
    return (int)(pow(cnt1,2)>cnt2);
    
    return answer;
}