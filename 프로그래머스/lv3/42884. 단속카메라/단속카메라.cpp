#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int flag;
    sort(routes.begin(),routes.end());
    flag = routes[0][1];
    for(int i=1;i<routes.size();i++){
        if(flag<routes[i][0]){
            answer++;
            flag = routes[i][1];
        }
        if(flag>=routes[i][1]){
            flag=routes[i][1];
        }
    }
    return ++answer;
}