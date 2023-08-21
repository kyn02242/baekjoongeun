#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target) {
    int answer = 0;
    if(my_string.find(target)!=-1){
        answer = 1;
    }
    return answer;
}