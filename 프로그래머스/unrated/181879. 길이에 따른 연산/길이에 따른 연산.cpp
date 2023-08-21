#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    if(num_list.size()<=10){
        answer = 1;
        for(int i=0;i<num_list.size();i++){
            answer*=num_list[i];   
        }
    }
    else{
        for(int i=0;i<num_list.size();i++){
            answer+=num_list[i];
        }
    }
    
    return answer;
}