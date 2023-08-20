#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cnt(101);

void DFS(int start, int now, vector<int> cards){
    if(cards[now]==start){
        cnt[start]++;
        return;
    }
    cnt[start]++;
    DFS(start,cards[now],cards);
    
    return;
}

int solution(vector<int> cards) {
    int answer = 0;
    
    for(int i=0;i<cards.size();i++){
        cards[i]-=1;
    }
    for(int i=0;i<cards.size();i++){
        if(i==cards[i]){
            cnt[i]=1;
            continue;
        }
        cnt[i]++;
        DFS(i,cards[i],cards);
    }
    sort(cnt.begin(),cnt.begin()+cards.size());
    answer = cnt[cards.size()-1]*cnt[cards.size()-1-cnt[cards.size()-1]];
    
    return answer;
}