#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(){   

    int n, m;
    string arr;
    int cnt = 0;
    cin >> n;
    cin >> m;
    cin >> arr;
    
    for (int i = 0; i < m; i++)
    {
        int flag = 0;

        if (arr[i] == 'O')
            continue;
        else
        {
            while (arr[i + 1] == 'O' && arr[i + 2] == 'I')
            {
                flag++;
                if (flag == n)
                {
                    cnt++;
                    flag--;
                }
                i += 2;
            }
            flag = 0;
        }
    }
    cout << cnt;

    return 0;
}
