#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <sstream>
#include <memory>
#include <deque>
#include <set>

using namespace std;

vector<int> v;

long long a,b,c;

long long CALCU(int b) {

    //cout<<b<<endl;

	if (b == 0) return 1;
	if (b == 1) return a % c;
	
	long long tmp = CALCU(b / 2) % c;
	if (b % 2 == 0) return tmp * tmp % c;
	return tmp * tmp % c * a % c;
}


int main()
{
    cin>>a>>b>>c;
    cout<<CALCU(b)<<endl;
    return 0;
}