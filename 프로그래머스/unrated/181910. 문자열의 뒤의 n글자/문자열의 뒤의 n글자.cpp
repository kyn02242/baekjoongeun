#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer(my_string.begin()+(my_string.length()-n),my_string.end());
    return answer;
}