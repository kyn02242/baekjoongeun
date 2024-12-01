#include <string>
#include <string.h>
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
#include <numeric>
#define endl '\n'
#define LINE cout << endl
#define MAX 300001

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    float n, m;
    cin >> n >> m;
    if(n >= m / 2){
        cout << 'E';
    }
    else{
        cout << 'H';
    }

    return 0;
}