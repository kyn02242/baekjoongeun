#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

float findScore(string str)
{
    float total = 4;
    char a = str[0];
    char b = str[1];

    total = total - a + 'A';
    if (b == '+')
        total += 0.5;
    return total;
}

int main()
{
    string name;
    float n;
    string score;

    float total = 0;
    float number = 0;

    for (int i = 0; i < 20; i++)
    {
        cin >> name >> n >> score;
        if (score == "P"){
            continue;
        }
        else if (score == "F"){
            number += n;
        }
        else{
            total += n * findScore(score);
            number += n;
        }
    }

    cout << total / number;
    return 0;
}