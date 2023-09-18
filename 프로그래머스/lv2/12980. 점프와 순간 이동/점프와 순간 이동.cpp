#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 1;
    while(n!=0){
        if(n==1){
            return ans;
        }
        if(n%2!=0){
            ans++;
            n--;
        }
        n/=2;
    }
    return ans;
}