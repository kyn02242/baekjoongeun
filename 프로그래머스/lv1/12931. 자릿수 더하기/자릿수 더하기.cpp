#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int flag = 10;
    while(n!=0){
        answer+=n%10;
        n/=10;
    }
    return answer;
}