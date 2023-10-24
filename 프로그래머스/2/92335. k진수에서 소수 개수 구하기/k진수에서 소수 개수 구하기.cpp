#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

bool check_prime(long long n) {
    long long tmp = 2;
    while (tmp <= sqrt(n)) {
        if (n % tmp == 0) {
            return false;
        }
        tmp++;
    }
    return true;
}


int solution(int n, int k) {
    int answer = 0;
    //k진수로 바꾸면서 0을 기준으로 저장
    //해당 저장된 수가 소수인지 확인
    vector<long long> v;
    string tmp = "";
    
    while (n != 0) {
        int ttmp = 0;
        ttmp = n % k;
        tmp += to_string(ttmp);
        n /= k;
    }
    reverse(tmp.begin(), tmp.end());

    //cout << tmp << endl;

    string ttmp = "";

    for (int i = 0; i < tmp.length(); i++) {
        //cout << "?? : " << i << endl;
        if (tmp[i] >= '1' && tmp[i] <= '9') {
            ttmp += tmp[i];
        }
        else {
            if (!ttmp.empty()) {
                v.push_back(stoll(ttmp));
                ttmp = "";
            }
        }
        if (!ttmp.empty() && i == tmp.length() - 1) {
            v.push_back(stoll(ttmp));
        }
    }


    for (auto i : v) {
        //cout << i << endl;

        if (i<2) {
            continue;
        }
        if (check_prime(i)) {
            //cout << i << endl;
            answer++;
        }
    }
    return answer;
}
