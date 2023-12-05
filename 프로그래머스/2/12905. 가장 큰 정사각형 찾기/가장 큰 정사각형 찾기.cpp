#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int max = 0;
    for (int i = 1; i < board.size(); i++)
    {
        for (int j = 1; j < board[0].size(); j++)
        {
            if (board[i][j] == 1)
            {
                board[i][j] = 1 + min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1]));
                if (board[i][j] > max)
                    max = board[i][j];
            }
        }
    }
    if(max == 0){
        if(board[0][0]==1||board[0][1]==1||board[1][0]==1)return 1;
    }
    answer = pow(max, 2);
    return answer;
}