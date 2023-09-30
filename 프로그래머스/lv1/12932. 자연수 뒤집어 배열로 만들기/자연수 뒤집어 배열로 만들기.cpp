#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    int flag = 10;
    while(n!=0){
        answer.push_back(n%flag);
        n/=10;
    }
    return answer;
}