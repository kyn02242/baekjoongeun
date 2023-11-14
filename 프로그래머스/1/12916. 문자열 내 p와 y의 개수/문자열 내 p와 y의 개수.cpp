#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p=0;
    int y=0;
    for(auto i : s){
        if(i=='p'||i=='P')p++;
        if(i=='y'||i=='Y')y++;
    }
    if(p!=y)answer = !answer;
    return answer;
}