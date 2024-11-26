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
#define MAX INT32_MAX

using namespace std;

deque<char> dq;

void isBomb(string bomb)
{
    string tmp = "";
    int bombLen = bomb.length();

    if (dq.size() < bombLen)
    { // 만약 스택이 더 작으면 종료
        return;
    }

    for (int i = 0; i < bombLen; i++)
    {
        tmp.push_back(dq.back());
        dq.pop_back();
    }
    reverse(tmp.begin(), tmp.end());

    // 같으면 종료 다르면 다시 집어넣기
    if (tmp != bomb)
    {
        for (int i = 0; i < bombLen; i++)
        {
            dq.push_back(tmp[i]);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 다음 턴에 터져야 하는데 미리 터져서 손해가 생길까?

    // 111111113136565에서 1365가 터진다면,
    // 111111113 65가 되는데, 스택은 중간까지 들어있다.
    // 이때, 어떤 방식으로 폭탄문자인지 확인할까?
    // 폭탄 문자의 마지막 문자가 입력될때마다, 스택에서 하나씩 빼면서 역순으로 확인하고, 맞으면 터트리고 아니면 그냥 넣기 할까? -> 좋아보이는데?

    string str;
    cin >> str;
    int strLen = str.length();

    string bomb;
    cin >> bomb;
    int bombLen = bomb.length();

    for (int i = 0; i < strLen; i++)
    {

        if (bomb[bombLen - 1] == str[i])
        { // 폭탄 문자의 마지막 문자가 들어온다면
            // 스택에 넣은 뒤, 스택의 위에 bomb 문자열이 있는지 확인
            dq.push_back(str[i]);
            isBomb(bomb);
        }
        // 그 외에는 스택에 저장
        else
        {
            dq.push_back(str[i]);
        }
    }

    if (dq.empty())
    {
        cout << "FRULA";
    }
    else
    {
        int dequeSize = dq.size();
        for (int i = 0; i < dequeSize; i++)
        {
            cout << dq.front();
            dq.pop_front();
        }
    }

    return 0;
}