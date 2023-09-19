#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i=0;i<arr1.size();i++){
        vector<int> vtmp;
        for(int j=0;j<arr2[0].size();j++){
            vtmp.push_back(0);
        }
        answer.push_back(vtmp);
    }
    int n = arr1[0].size();
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr2[0].size();j++){
            for(int k = 0;k<n;k++){
                answer[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }
    
    
    return answer;
}