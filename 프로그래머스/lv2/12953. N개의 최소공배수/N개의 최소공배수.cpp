#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(),arr.end());
    for(int i=arr[arr.size()-1];;i++){
        int cnt = 0;
        for(int j=0;j<arr.size();j++){
            if(i%arr[j]==0){
                cnt++;
            }
        }
        if(cnt==arr.size()){
            return i;
        }
    }
    
    
    
    return answer;
}