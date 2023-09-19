#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i=left;i<=right;i++){
        long long r = i/n+1;
        long long l = i%n+1;
        if(r>=l){
            answer.push_back(r);
        }
        else{
            answer.push_back(l);
        }
    }
    return answer;
}