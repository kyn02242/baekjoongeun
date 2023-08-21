#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int num = n;
    int sum = 0;
    if(s<n){
        answer.push_back(-1);
        return answer;
    }
    while(num>=1){
        answer.push_back((s-sum)/num);
        sum+=(s-sum)/num;
        num--;
        if(sum==s){
            break;
        }
    }
    
    return answer;
}