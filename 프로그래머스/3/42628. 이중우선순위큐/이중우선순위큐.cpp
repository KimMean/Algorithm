#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> rpq;
    int cnt = 0;
    
    for(int i = 0; i < operations.size(); i++)
    {
        int value = 0;
        switch(operations[i][0])
        {
            case 'I' :
                value = stoi(operations[i].substr(1));
                pq.push(value);
                rpq.push(value);
                cnt++;
                break;
            case 'D' :
                if(cnt == 0) continue;
                
                value = stoi(operations[i].substr(1));
                if(value > 0)
                    pq.pop();
                else
                    rpq.pop();
                
                cnt--;
                if(cnt == 0)
                {
                    pq = priority_queue<int>();
                    rpq = priority_queue<int, vector<int>, greater<int>>();
                }
                break;
        }
    }
    
    if(cnt >0)
    {
        answer[0] = pq.top();
        answer[1] = rpq.top();
    }
    
    return answer;
}