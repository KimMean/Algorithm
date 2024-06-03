#include <string>
#include <vector>

using namespace std;

// 현재 행에 다른 퀸이 있는지 확인
bool IsSameRow(int placedRow, int currentRow) { return placedRow == currentRow; }

// 대각선에 다른 퀸이 있는지 확인
bool IsDiagonalAttack(int placedCol, int placedRow, int currentCol, int currentRow)
{
    return abs(placedCol - currentCol) == abs(placedRow - currentRow);
}

// 안전성 쳌
bool IsSafePosition(const vector<int> &queen, int col, int row)
{
    for(int i = 0; i < col; i++)
    {
        if(IsSameRow(queen[i], row) || IsDiagonalAttack(i, queen[i], col, row))
            return false;
    }
    return true;
}

// 퀸 배치
long long PlaceQueens(vector<int> &queen, int col)
{
    int n = queen.size();
    if(col == n)
        return 1;
    
    long long count = 0;
    for(int row = 0; row < n; row++)
    {
        if(IsSafePosition(queen, col, row))
        {
            queen[col] = row;
            count += PlaceQueens(queen, col + 1);
            queen[col] = -1;
        }
    }
    return count;
}

int solution(int n) {
    int answer = 0;
    
    //if(n > 4) return 0;
    vector<int> queen(n, -1);
        
    return PlaceQueens(queen, 0);
}