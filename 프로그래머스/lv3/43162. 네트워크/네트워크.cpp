#include <string>
#include <vector>

using namespace std;

bool visited[201] = {false};

void DFS(int start,int n,vector<vector<int>> computer){
    visited[start] = true;
    for(int i=0;i<n;i++){
        if(i!=start&&computer[start][i]==1&&visited[i]==false){
            DFS(i,n,computer);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            answer++;
            DFS(i,n,computers);
        }    
    }
    
    
    
    return answer;
}