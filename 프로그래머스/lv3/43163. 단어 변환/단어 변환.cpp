#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
vector<vector<int>> v(52,vector<int>(52));
int n,num;
vector<int> vcount(52);

int BFS(vector<string> words,string target){
    vcount[n-1] = -1;
    for(int i=0;i<n;i++){
        if(v[n-1][i]==1){
            q.push(i);
            vcount[i]++;
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(words[x]==target){
            return vcount[x];
        }
        for(int i=0;i<n;i++){
            if(v[x][i]==1&&vcount[i]==0){
                vcount[i] = vcount[x]+1;
                q.push(i);
            }
        }
    }
    return 0;
}



int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    
    num = begin.length();
    n = words.size()+1;
    words.push_back(begin);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                v[i][j] = 0;
                continue;
            }
            int cnt = 0;
            for(int k=0;k<num;k++){
                if(words[i][k]==words[j][k]){
                    cnt++;
                }
            }
            v[i][j] = num - cnt;
            v[j][i] = num - cnt;
        }
    }
    answer = BFS(words,target);
    return answer;
}