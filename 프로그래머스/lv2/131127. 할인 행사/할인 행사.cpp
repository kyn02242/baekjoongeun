#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for(int i=0;i<=discount.size()-10;i++){
        vector<int> v(number.size(),0);
        int cnt = 0;
        for(int j=0;j<10;j++){
            for(int k=0;k<want.size();k++){
                if(discount[i+j]==want[k]){
                    v[k]++;
                    cnt++;
                    break;
                }
            }
        }
        if(cnt!=10){
            continue;
        }
        else{
            int flag = 0;
            for(int j = 0;j<number.size();j++){
                if(v[j]!=number[j]){
                    break;
                }
                else{
                    flag++;
                }
            }
            if(flag == number.size()){
                answer++;
            }
        }
    }
    
    
    return answer;
}