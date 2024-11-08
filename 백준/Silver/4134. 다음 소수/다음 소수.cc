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
#define endl '\n'

using namespace std;

bool check(long long n)
{
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    long long number;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        if(number == 0){
            cout<<2<<endl;
            continue;
        }
        if(number == 1){
            cout<<2<<endl;
            continue;
        }
        for (long long j = number;; j++)
        {
            if (check(j))
            {
                cout << j << endl;
                break;
            }
        }
    }

    return 0;
}
