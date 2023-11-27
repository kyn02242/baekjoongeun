#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    int start = 0, end = 0;
    int sum = sequence[0];
    int len = sequence.size()+1;
    
    while (start <= end && end < sequence.size()) {
        if (sum < k) sum += sequence[++end];
        else if (sum == k) {
            if (end-start+1 < len) {
                len = end-start+1;
                answer[0] = start;
                answer[1] = end;
            } else if (end-start+1 == len) {
                if (start < answer[0]) {
                    answer[0] = start;
                    answer[1] = end;
                }
            }
            
            sum -= sequence[start++];
        } 
        else sum -= sequence[start++];
    }
    
    return answer;
}