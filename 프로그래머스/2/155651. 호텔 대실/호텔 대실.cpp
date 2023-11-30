#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<int> vtime(2000,0);
    for(int i=0;i<book_time.size();i++){
        string starthour = "";
        string startmin = "";
        string endhour = "";
        string endmin = "";
        starthour[0] = book_time[i][0][0];
        starthour[1] = book_time[i][0][1];
        startmin[0] = book_time[i][0][3];
        startmin[1] = book_time[i][0][4];
        endhour[0] = book_time[i][1][0];
        endhour[1] = book_time[i][1][1];
        endmin[0] = book_time[i][1][3];
        endmin[1] = book_time[i][1][4];
        int starttime = stoi(starthour)*60+stoi(startmin);
        int endtime = stoi(endhour)*60+stoi(endmin);
        for(int j=starttime;j<=endtime+9;j++){
            vtime[j]++;
        }
    }
    sort(vtime.rbegin(),vtime.rend());
    answer = vtime[0];
    
    return answer;
}