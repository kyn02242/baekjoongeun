#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<int>> v(501,vector<int>(501));

int CALCU(vector<vector<int>> origin){
    v[0][0] = origin[0][0];
    for(int i=1;i<origin.size();i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                v[i][j] = v[i-1][j]+origin[i][j];
            }
            if(i==j){
                v[i][j] = v[i-1][j-1]+origin[i][j];
            }
            else{
                v[i][j] = max(v[i-1][j-1],v[i-1][j])+origin[i][j];
            }
            
        }
    }
    sort(v[origin.size()-1].begin(),v[origin.size()-1].begin()+origin.size());
    return v[origin.size()-1][origin.size()-1];
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    answer = CALCU(triangle);
    return answer;
}