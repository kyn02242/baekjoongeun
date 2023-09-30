#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int ans = 0;
    while(ans!=1){
        if(n%answer==1){
            break;
        }
        answer++;
    }
    return answer;
}