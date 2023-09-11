#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown+yellow;
    for(int i=3;i<=total;i++){
        for(int j=3;j<=i;j++){
            if(i*j==total){
                if((i-2)*(j-2)==yellow){
                    answer.push_back(i);
                    answer.push_back(j);
                }
            }
            else if(i*j>total){
                break;
            }
        }
    }
    return answer;
}