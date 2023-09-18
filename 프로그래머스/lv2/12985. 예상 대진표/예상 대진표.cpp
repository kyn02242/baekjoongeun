#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    while(1){
        if(a==b)return answer;
        answer++;
        if(a%2!=0){
            a=(a+1)/2;
        }
        else{
            a/=2;
        }
        if(b%2!=0){
            b=(b+1)/2;
        }
        else{
            b/=2;
        }
    }
    return answer;
}