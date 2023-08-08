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

int n, m;

vector<int> v(10);
vector<int> tmpv(10);

void CALCU(int x, int cnt)
{
	//cout<<cnt<<" "<<m<<endl;
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << tmpv[i]<<" ";
		}
		cout << endl;
		return;
	}

	int last = 0;

	for (int i = x; i < n; i++)
	{
		if (v[i] != last)
		{
			tmpv[cnt] = v[i];
			last = tmpv[cnt];
			CALCU(i, cnt + 1);
		}
	}
	return;
}

int main()
{
	cin >> n >> m;

	//cout<<n<<" "<<m<<endl;

	for (int i = 0; i < n; i++)
	{
		cin>>v[i];
	}

	sort(v.begin(), v.begin()+n);

	// for (int i = 0; i < n; i++)
	// {
	// 	cout << v[i]<<" ";
	// }
	// cout<<endl;

	CALCU(0, 0);

	return 0;
}