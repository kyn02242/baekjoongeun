#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <sstream>
#include <memory>
#include <deque>

using namespace std;

vector<int> button(10, 1); //index = 번호

int c1 =0,c2=0,c3=0;//c1 = 그저 거리,c2 = 위로 횟수,c3 = 아래로 횟수

int howlong(int n){
    int tmp_n = n;
    int cnt=0;
    while(tmp_n>0){
        //cout<<"here?"<<endl;
        tmp_n/=10;
        cnt++;
    }
    if(cnt==0){
        cnt++;
    }
    return cnt;
}

bool avail(int n)// 숫자를 버튼으로 누를 수 있는지 확인
{
    int n_tmp = n;
    
    while (n_tmp / 10 != 0)
    {
        if(button[n_tmp%10]==0){
            return false;
        }
        else{
            n_tmp/=10;
        }
    }
    if(button[n_tmp]==0){
        return false;
    }
    return true;
}

int just_distance(int target, int now)//목표를 +,-만으로 이동할때 눌러야 할 횟수
{
    if (target >= now)
    {
        return target - now;
    }
    else
    {
        return now - target;
    }
    return 987654321;
}

int low_max(int target)//목표보다 낮은 값중 가장 큰 값
{
    int tmp_target = target;
    while (tmp_target>=0)
    {
        if(avail(tmp_target)==true){
            return c3+howlong(tmp_target);
        }
        tmp_target--;
        c3++;
    }
    return 987654321;
}

int high_min(int target)//목표보다 큰 값중 가장 작은 값
{
    int tmp_target = target;
    while (tmp_target<=1000000)
    {
        if(avail(tmp_target)==true){
            return c2+howlong(tmp_target);
        }
        tmp_target++;
        c2++;
    }
    return 987654321;
}


int main()
{
    int ans;
    int target;
    int wrongnum;

    cin >> target;
    cin >> wrongnum;
    int tmp1=0;
    int tmp2=0;
    for (int i = 0; i < wrongnum; i++)
    {
        int tmp;
        cin >> tmp;
        button[tmp] = 0;
    }
    c1 = just_distance(target,100);
    if(c1!=0){
        tmp1 = low_max(target);
        tmp2 = high_min(target);
    }
    else{
        cout<<0<<endl;
        return 0;
    }

    //cout<<c1<<" "<<c2<<" "<<c3<<endl;
    ans = min(tmp1,tmp2);
    ans = min(ans,c1);
    cout<<ans<<endl;

    return 0;
}