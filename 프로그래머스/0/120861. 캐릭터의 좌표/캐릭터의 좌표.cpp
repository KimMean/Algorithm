#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer(2, 0);
    
    for(string s : keyinput)
    {
        if(s == "up" && answer[1] < +board[1] / 2) answer[1]++;
        else if (s == "down" && answer[1] > -board[1] / 2) answer[1]--;
        else if (s == "left" && answer[0] > -board[0] / 2) answer[0]--;
        else if (s == "right" && answer[0] < +board[0] / 2) answer[0]++;
    }
    return answer;
}