#include <string>
#include <vector>
#include <algorithm>
#define MAX 987654321

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    bool check = false;
    sort(people.begin(), people.end());
    int i = 0;
    int j = people.size()-1;
    while(1){
        if(i==j){
            answer++;
            break;
        }
        if(i>j){
            break;
        }
        if(people[i]+people[j]<=limit){
            answer++;
            i++;
            j--;
        }
        else{
            answer++;
            j--;
        }
    }
    return answer;
}
