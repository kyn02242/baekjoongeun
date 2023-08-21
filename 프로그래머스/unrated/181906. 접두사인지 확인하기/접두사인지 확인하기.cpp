#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 0;
    if(my_string.find(is_prefix)==0){
        answer = 1;
    }
    return answer;
}