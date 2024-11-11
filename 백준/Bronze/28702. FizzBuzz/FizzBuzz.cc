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
#include <deque>
#define endl '\n'
using namespace std;

bool checkFB(string str)
{
    if (str == "Fizz" || str == "Buzz" || str == "FizzBuzz")
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> v(3);
    int answerNum;

    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
        if (!checkFB(v[i]))
        {
            answerNum = stoi(v[i]) + 3 - i;
        }
    }

    string answerString = "";

    if (answerNum % 3 == 0)
    {
        answerString += "Fizz";
    }
    if (answerNum % 5 == 0)
    {
        answerString += "Buzz";
    }

    if (answerString == "")
    {
        answerString = to_string(answerNum);
    }

    cout << answerString;

    return 0;
}
