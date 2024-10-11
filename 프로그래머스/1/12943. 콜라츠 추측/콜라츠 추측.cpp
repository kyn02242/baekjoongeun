#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long num1 = num;
    if (num1 == 1){
        return 0;
    }
    
    for (int i = 1; i < 501; i++){
        if (num1 % 2 == 0){
            num1 /= 2;
        }
        else{
            num1 = num1 * 3 + 1;
        }
        
        if (num1 == 1){
            return i;
        }
    }
    return -1;
}