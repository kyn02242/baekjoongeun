#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> q;
    for(int i=0;i<scoville.size();i++){
        q.push(-1*scoville[i]);
    }
    while(1){
        int tmp1 = q.top();
        if(tmp1<=-1*K) break;
        if(q.size()<=1)return -1;
        q.pop();
        int tmp2 = q.top();
        q.pop();
        q.push(tmp1+tmp2*2);
        answer++;
    }
    return answer;
}
