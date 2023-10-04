#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int flag = 0;
    while(1){
        int cnt = 0;
        while(progresses[flag]<100){
            for(int i=0;i<progresses.size();i++){
                progresses[i]+=speeds[i];
            }
        }
        while(progresses[flag]>=100){
            flag++;
            cnt++;
            if(flag == progresses.size()){
                break;
            }
        }
        answer.push_back(cnt);
        if(flag == progresses.size()){
            break;
        }
    }
    return answer;
}