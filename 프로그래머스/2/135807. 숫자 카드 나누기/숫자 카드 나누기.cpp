#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    sort(arrayA.begin(),arrayA.end());
    sort(arrayB.begin(),arrayB.end());

    int flag = arrayA[0];
    for(int i = 1 ; i < arrayA.size() ;i++){
        flag = gcd(flag, arrayA[i]);
        if(flag == 1) break;
    }
    if(flag != 1){
        int i;
        for(i = 0 ; i < arrayB.size() ;i++){
            if(arrayB[i] % flag == 0) break;
        }
        if(i == arrayB.size()) answer = flag;
    }
    flag = arrayB[0];
    for(int i = 1 ; i < arrayB.size() ;i++){
        flag = gcd(flag, arrayB[i]);
        if(flag == 1) break;
    }
    if(flag != 1){
        int i;
        for(i = 0 ; i < arrayA.size() ;i++){
            if(arrayA[i] % flag == 0) break;
        }
        if(i == arrayA.size()) answer = max(flag,answer);
    }
    return answer;
}