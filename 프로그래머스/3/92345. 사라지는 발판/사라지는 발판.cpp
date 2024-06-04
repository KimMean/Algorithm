#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
int n, m;

bool IsOutOfBounds(int r, int c) { return r < 0 || r >= n || c < 0 || c >= m; }
int PlayGame(vector<vector<int>> & board, int curR, int curC, int opR, int opC)
{
    if(board[curR][curC] == 0)
        return 0;
    
    int bestSteps = 0;
    
    for(int dir = 0; dir < 4; dir++)
    {
        int nextR = curR + dx[dir];
        int nextC = curC + dy[dir];
        
        if(IsOutOfBounds(nextR, nextC) || board[nextR][nextC] == 0)
            continue;
        
        board[curR][curC] = 0;
        int steps = PlayGame(board, opR, opC, nextR, nextC) + 1;
        board[curR][curC] = 1;
        
        if(bestSteps % 2 == 0 && steps % 2 == 1)
            bestSteps = steps;
        else if (bestSteps % 2 == 0 && steps % 2 == 0)
            bestSteps = max(bestSteps, steps);
        else if(bestSteps % 2 == 1 && steps % 2 == 1)
            bestSteps = min(bestSteps, steps);
    }
    return bestSteps;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    n = board.size();
    m = board[0].size();
    
    return PlayGame(board, aloc[0], aloc[1], bloc[0], bloc[1]);
}