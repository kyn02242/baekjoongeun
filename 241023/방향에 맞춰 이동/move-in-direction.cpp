#include <iostream>

using namespace std;

int main()
{
    char dir;
    int num;
    int n;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int x = 0;
    int y = 0;
    int flag;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> dir >> num;
        if (dir == 'N')
            flag = 0;
        else if (dir == 'E')
            flag = 1;
        else if (dir == 'S')
            flag = 2;
        else if (dir == 'E')
            flag = 3;

        x += dx[flag] * num;
        y += dy[flag] * num;
    }

    cout << x << ' ' << y;
    return 0;
}