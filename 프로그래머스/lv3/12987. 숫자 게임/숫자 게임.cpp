#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int flag = 0;
    int n = A.size();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0;i<n;i++){
        if(A[i]<B[flag]){
            answer++;
            flag++;
            continue;
        }
        else{
            while(A[i]>=B[flag]){
                flag++;
                if(flag>=n){
                    break;
                }
            }
            if(flag>=n){
                break;
            }
            else{
                answer++;
                flag++;
            }
        }
    }
    return answer;
}