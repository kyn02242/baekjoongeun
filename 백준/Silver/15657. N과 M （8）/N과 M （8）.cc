#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int arr[9];
int brr[9];
int crr[9];
int drr[9];
void fuck(int flag, int n, int m)
{
    int cnt = 0;
    if (flag == m)
    {
        for (int i = 0; i < m; i++)
        {
            drr[i] = crr[i];
        }
        sort(drr, drr + m);
        for (int i = 0; i < m; i++)
        {
            if (crr[i] == drr[i])
            {
                cnt++;
            }
        }
        if (cnt == m)
        {
            for (int i = 0; i < m; i++)
            {
                cout << crr[i] << " ";
            }
            cout << '\n';
            return;
        }
        else{
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (brr[i] == 0)
        {
            crr[flag] = arr[i];
            fuck(flag + 1, n, m);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    fuck(0, n, m);
}
