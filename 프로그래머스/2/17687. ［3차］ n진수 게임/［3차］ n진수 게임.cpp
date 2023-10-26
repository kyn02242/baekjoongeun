#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string st = "0";
    //n진법으로 표현한것을 쭉 나열하고, m명중 p번째 수만 뽑아서 저장한다
    for (int i = 1; st.size() < m * t; i++) {
        string tmp = "";
        int num = i;
        while (num != 0) {
            int ttmp = num % n;
            if (ttmp > 9) {
                tmp += 'A' + ttmp - 10;
            }
            else {
                tmp += to_string(num % n);
            }
            num /= n;
        }
        reverse(tmp.begin(), tmp.end());
        st += tmp;
    }
    for (int i = 0; answer.size() < t; i++) {
        answer += st[p-1 + m * i];
    }
    return answer;
}