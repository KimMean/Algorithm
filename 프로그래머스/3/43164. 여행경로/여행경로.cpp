#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer;
bool Check[10000];
bool isAnswer = false;

void dfs(vector<vector<string>>& tickets, string start, int count)
{
    answer.push_back(start);
    
    if(count == tickets.size())
    {
        isAnswer = true;
        return;
    }
    
    for(int i = 0; i < tickets.size(); i++)
    {
        // 이미 사용한 티켓
        if(Check[i]) continue;
        // 출발지 검색
        if(tickets[i][0] == start)
        {
            Check[i] = true;
            dfs(tickets, tickets[i][1], count + 1);
            
            if(!isAnswer)
            {
                answer.pop_back();
                Check[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    string start = "ICN";
    dfs(tickets, start, 0);
    
    return answer;
}