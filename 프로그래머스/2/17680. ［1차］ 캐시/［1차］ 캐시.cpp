#include <vector>
#include <iostream>
#include <string>

using namespace std;


int solution(int cacheSize, vector<string> cities) {

    int answer = 0;
    vector<string> v;
    bool hit = false;
    int start = 0;
    for(int i=0;i<cities.size();i++){
        for(int k=0;k<cities[i].length();k++){
            cities[i][k] = tolower(cities[i][k]);
        }
        for(int j=start;j<v.size();j++){
            if(cities[i]==v[j]){
                hit = true;
                for(int k = j;k<v.size()-1;k++){
                    v[k] = v[k+1];
                }
                v[v.size()-1] = cities[i];
                break;
            }
        }
        if(hit){
            answer++;
        }
        else{
            answer+=5;
            v.push_back(cities[i]);
            if(v.size()>cacheSize){
                start++;
            }
        }
        hit = false;
    }
    
    return answer;
}

