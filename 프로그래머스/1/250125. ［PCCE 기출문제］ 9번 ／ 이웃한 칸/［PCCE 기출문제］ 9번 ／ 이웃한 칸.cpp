#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    if(h-1 >= 0)
        if(board[h][w] == board[h-1][w]) answer++;
    if(w-1 >= 0)
        if(board[h][w] == board[h][w-1]) answer++;
    if(h+1 <= board.size()-1)
        if(board[h][w] == board[h+1][w]) answer++;
    if(w+1 <= board[w].size()-1)
        if(board[h][w] == board[h][w+1]) answer++;
    return answer;
}