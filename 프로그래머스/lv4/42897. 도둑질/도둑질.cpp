#include <string>
#include <vector>

using namespace std;

int DP_zero[1000001];
int DP_one[1000001];
 
int solution(vector<int> money)
{
    DP_zero[0] = money[0];
    DP_zero[1] = DP_zero[0];
    DP_one[0] = 0;
    DP_one[1] = money[1];
    
    for (int i = 2; i < money.size(); i++)
    {
        if(i<money.size()-1){
            DP_zero[i] = max(DP_zero[i - 2] + money[i], DP_zero[i - 1]);
        }
        DP_one[i] = max(DP_one[i - 2] + money[i], DP_one[i - 1]);
    }
    
    return max(DP_zero[money.size() - 2], DP_one[money.size()-1]);
}
