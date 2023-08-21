#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag) {
    int answer = 0;
    
    if(flag){
        answer += a+b;
    }
    else{
        answer += a-b;
    }
    
    return answer;
}