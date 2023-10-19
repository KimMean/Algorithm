#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int cnt;
    priority_queue<int> pq;
    queue<int> q;
    
    for(int i = 0 ; i < priorities.size(); i++)
    {
        pq.push(priorities[i]);
        q.push(priorities[i]);
    }
    
    while(!q.empty())
    {
        int value = q.front();
        q.pop();
        if(value < pq.top())
        {
            q.push(value);
        }
        else
        {
            answer++;
            pq.pop();        
            if(location == 0)
                break;
        }

        location--;
        if(location < 0)
            location = q.size() - 1;
    }
    
    
    return answer;
}