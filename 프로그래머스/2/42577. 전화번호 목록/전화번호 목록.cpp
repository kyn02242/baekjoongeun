#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    int n = phone_book.size();
    for (int i = 0; i < n - 1; i++)
    {
        int j = i + 1;
        int cnt = 0;
        for (int k = 0; k < phone_book[i].length(); k++)
        {
            if (phone_book[i][k] == phone_book[j][k])
            {
                cnt++;
            }
            else
            {
                continue;
            }
        }
        if (cnt == phone_book[i].length())
        {
            return false;
        }
    }
    return answer;
}