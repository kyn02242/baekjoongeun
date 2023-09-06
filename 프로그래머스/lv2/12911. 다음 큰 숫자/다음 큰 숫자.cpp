#include <string>
#include <vector>

using namespace std;

int CALCU(int n){
    int cnt = 0;
    while(n!=0){
        if(n%2==1){
            cnt++;
        }
        n/=2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    for(int i=1;;i++){
        answer = CALCU(n);
        if(CALCU(n+i)==answer){
            answer = n+i;
            break;
        }
    }
    
    return answer;
}