#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list, int n) {
    int answer = 0;
    sort(num_list.begin(),num_list.end());
    int i=0;
    while(1){
        if(num_list[i]==n){
            answer = 1;
            break;
        }
        if(num_list[i]>n){
            break;
        }
        i++;
    }
    return answer;
}