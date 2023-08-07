#include <iostream>
#include <string>
#include<cstring>
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



void BFS(int start, int end)
{
    queue<int> q;
    vector<string> visited(10001);

    q.push(start);
    visited[start] = "";

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        // cout<<"x : "<<x<<endl;
        // cout<<"visited[x] : "<<visited[x]<<endl;

        if (x == end)
        {
            cout << visited[x] << endl;
            break;
        }
        //========================================================D
        if (x * 2 >= 10000&&x!=0)
        {
            if (visited[(x * 2) % 10000] == "")
            {
                visited[(x * 2) % 10000]=visited[x]+'D';
                q.push((x * 2) % 10000);
                //cout << "wtf1-1" << endl;
            }
        }
        else
        {
            if (visited[2 * x] == ""&&x!=0)
            {
                q.push(x * 2);
                visited[2 * x] = visited[x] + 'D';
                //cout << "wtf1-2" << endl;
            }
        }
        //========================================================S
        if (x - 1 == -1)
        {
            if (visited[9999] == "")
            {
                q.push(9999);
                visited[9999] =visited[x]+ 'S';
                //cout << "wtf2-1" << endl;
            }
        }
        else
        {
            if (visited[x - 1] == "")
            {
                q.push(x - 1);
                visited[x - 1] =visited[x]+ 'S';
                //cout << "wtf2-2" << endl;
            }
        }
        
        //========================================================L
        if (visited[(x * 10) % 10000 + x / 1000] == "")
        {
            visited[(x * 10) % 10000 + x / 1000] =visited[x]+ 'L';
            q.push((x * 10) % 10000 + x / 1000);
            //cout << "wtf3 : " << (x * 10) % 10 + x / 1000 << endl;
        }
        
        //========================================================R
        if (visited[(x % 10) * 1000 + x / 10] == "")
        {
            visited[(x % 10) * 1000 + x / 10] =visited[x]+ 'R';
            q.push((x % 10) * 1000 + x / 10);           
            //cout << "wtf4" << endl;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    int start, end;
    for (int i = 0; i < T; i++)
    {
        cin >> start >> end;
        BFS(start, end);
    }

    return 0;
}