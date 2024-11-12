#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <deque>
#define endl '\n'
#define MAX 100
using namespace std;

int calculate(string S, string F)
{ // S의 각 문자가 F의 문자중 하나로 바뀌는 최솟값 계산
    // a~z가 F로 바뀌는 최소 수를 먼저 전부 구하고 각각의 수를 더하는 방식으로 구현
    int sum = 0;
    int tmp;
    vector<int> v(26, MAX); // a~z
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < F.length(); j++)
        {
            tmp = abs((int)('a' + i - F[j]));
            if (tmp > 13)
            {
                tmp = 26 - tmp;
            }
            v[i] = min(v[i], tmp);
        }
    }

    for (int i = 0; i < S.length(); i++)
    {
        sum += v[S[i] - 'a'];
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    string S;
    string F;

    for (int i = 0; i < T; i++)
    {
        cin >> S;
        cin >> F;
        cout << "Case #" << i + 1 << ": " << calculate(S, F) << endl;
    }
    return 0;
}
