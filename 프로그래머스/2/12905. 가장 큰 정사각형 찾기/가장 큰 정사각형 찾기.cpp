#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int row = board.size(), col = board[0].size();
    
    for(int i = 1; i < row; i++)
    {
        for(int j = 1; j < col; j++)
        {
            if(board[i][j] == 1)
            {
                int up = board[i-1][j];
                int left = board[i][j-1];
                int up_left = board[i-1][j-1];
                
                board[i][j] = min(min(up, left), up_left) + 1;
            }
        }
    }
    
    int max_val = 0;
    for(const auto &row : board)
        max_val = max(max_val, *max_element(row.begin(), row.end()));
    
    return max_val * max_val;
}