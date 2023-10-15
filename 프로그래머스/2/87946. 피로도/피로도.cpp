#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;
vector<bool> check(8,false);

void dfs(int cnt, int k,vector<vector<int>> &dungeons) {
    if (cnt > ans) ans = cnt;
    for (int i=0; i<dungeons.size(); i++) {
        if (!check[i] && dungeons[i][0] <= k) {
            check[i] = true;
            dfs(cnt + 1, k - dungeons[i][1],dungeons);
            check[i] = false;
        }
    }
}


int solution(int k, vector<vector<int>> dungeons) {
    dfs(0,k,dungeons);
    int answer = ans;
    return answer;
}