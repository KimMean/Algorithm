#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    // prev = 10초 전
    // next = 10초 후
    // op_start <= now <= op_end 오프닝 끝 위치
    // mm:ss
    int videoTime = stoi(video_len.substr(0,2)) * 60 + stoi(video_len.substr(3,2));
    int posTime = stoi(pos.substr(0,2)) * 60 + stoi(pos.substr(3,2));
    int opsTime = stoi(op_start.substr(0,2)) * 60 + stoi(op_start.substr(3,2));
    int opeTime = stoi(op_end.substr(0,2)) * 60 + stoi(op_end.substr(3,2));
    
    
    if(opsTime <= posTime && posTime <= opeTime)
    {
        posTime = opeTime;
    }
    
    for(int i = 0; i < commands.size(); i++)
    {
        if(commands[i] == "next")
        {
            posTime += 10;
            if(posTime >= videoTime)
                posTime = videoTime;
            
            if(opsTime <= posTime && posTime <= opeTime)
            {
                posTime = opeTime;
            }
        }
        else
        {
            posTime -= 10;
            
            if(posTime < 0)
                posTime = 0;
            
            if(opsTime <= posTime && posTime <= opeTime)
            {
                posTime = opeTime;
            }
        }
    }
    
    int m = posTime / 60;
    int s = posTime % 60;
    ostringstream timeStream;
    timeStream << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s;
    
    answer = timeStream.str();
    return answer;
}