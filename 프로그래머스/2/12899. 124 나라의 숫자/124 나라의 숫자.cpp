#include <string>
#include <vector>
#include <iostream>

using namespace std;

string Three(int num){
    if(num==0){
        return "0"; 
    }
	string base = "";
    for(int i = num; i > 0; ){
    	base = to_string(i % 3) + base;
        i /= 3;
    }
    return base;
}

string solution(int n) {
    string answer = "";
    // a,b,c
//     1    a = 0
//     2    b = 1
//     3    c = 2
//     4    aa = 00
//     5    ab = 01
//     6    ac = 02
//     7    ba = 10
//     8    bb = 11
//     9    bc = 12
//     10 = 3 + 7    ca = 20
//     11    cb = 21
//     12    cc = 22
//     13    aaa = 000
//     14 = 3 + 9 + 2    aab = 001 => 112
    int flag = 3;
    int cnt = 0;
    while(n>flag){
        cnt++;
        n-=flag;
        flag*=3;
    }
    n-=1;
    //n을 cnt+1자리의 3진법으로 표현해야함
    //1.n을 3진법으로 표현
    string s = Three(n);
    //2.변환된 문자열의 0을 1로, 1을 2로, 2를 4로 변환
    for(int i=0;i<s.length();i++){
        if(s[i]=='0')s[i]='1';
        else if(s[i]=='1')s[i] = '2';
        else s[i] = '4';
    }
    //3.이후 cnt+1자리를 맞추기 위해 앞에 1을 필요한 만큼 추가
    string tmp = "1";
    answer = s;
    for(int i=0;i<cnt+1-s.length();i++){
        //cout<<"count : "<< cnt+1-s.length() <<endl;
        answer = tmp + answer;
    }
    return answer;
}