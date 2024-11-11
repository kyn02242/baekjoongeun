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
#include <stack>
#define endl '\n'

using namespace std;

stack<int> st;
queue<int> q;

int main()
{
    cin.tie(NULL);

    int n;
    cin >> n;
    int tmp;
    int order = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        q.push(tmp);
    }

    while (!q.empty())
    {
        tmp = q.front();
        if (tmp == order)
        { // 기존 줄에 다음 순서 수가 있을 때
            q.pop();
            order++;
        }
        else
        {
            if (st.empty())
            { // 다음 수가 아닌데 스택이 비어있으면
                q.pop();
                st.push(tmp);
            }
            else if (st.top() == order)
            { // 다음 수가 스택의 맨 위에 있으면
                st.pop();
                order++;
            }
            else if (st.top() > tmp)
            { // 스택의 맨 위가 기존 줄에서 나온 수보다 클 때에는 스택의 맨 위에 넣을 수 있다
                st.push(tmp);
                q.pop();
            }
            else
            { // 스택에 더 작은 수가 들어있다면 불가능으로 거기서 종료
                cout << "Sad";
                return 0;
            }
        }
    }
    cout << "Nice";

    return 0;
}