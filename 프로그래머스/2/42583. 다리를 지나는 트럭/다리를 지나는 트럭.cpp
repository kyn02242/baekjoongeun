#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int idx = 0;
    int tmp_weight;

    queue<int> q;

    while(1){
        if(idx == truck_weights.size()){
            answer += bridge_length;
            break;
        }

        answer++;
        tmp_weight = truck_weights[idx];

        if(q.size() == bridge_length){
            sum -= q.front();
            q.pop();
        }

        if(sum + tmp_weight <= weight){// 올릴 수 있으면
            sum+=tmp_weight;
            q.push(tmp_weight);
            idx++;
        }
        else{ // 못올리면
            q.push(0);
        }
    }

    return answer;
}