#include <string>
#include <vector>
#include <cmath>
#define MAX 987654321

using namespace std;

int CALCU(int m, int n, int x, int y, int Newx, int Newy)
{
    int total = MAX;
    if (x != Newx || y <= Newy)
    {
        total = min(total, (int)(pow(x - Newx, 2) + pow(y + Newy, 2)));
    }
    if (x >= Newx || y != Newy)
    {
        total = min(total, (int)(pow(x - 2 * m + Newx, 2) + pow(y - Newy, 2)));
    }
    if (x != Newx || y >= Newy)
    {
        total = min(total, (int)(pow(x - Newx, 2) + pow(y - 2 * n + Newy, 2)));
    }
    if (x <= Newx || y != Newy)
    {
        total = min(total, (int)(pow(x + Newx, 2) + pow(y - Newy, 2)));
    }
    return total;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
    vector<int> answer;

    for (int i = 0; i < balls.size(); i++)
    {
        answer.push_back(CALCU(m, n, startX, startY, balls[i][0], balls[i][1]));
    }

    return answer;
}