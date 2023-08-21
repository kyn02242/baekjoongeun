#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    if(k%2){
        for(int i=0;i<arr.size();i++){
            answer.push_back(arr[i]*k);
        }
    }
    else{
        for(int i=0;i<arr.size();i++){
            answer.push_back(arr[i]+k);
        }
    }
    return answer;
}