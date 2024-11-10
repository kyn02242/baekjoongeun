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

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int check(int n)
{
    int cnt = 0;
    for (int i = n + 1; i <= 2 * n; i++)
    {
        if(isPrime(i)){
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        cout << check(n) << endl;
    }

    return 0;
}
