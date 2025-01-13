#include <string>
#include <vector>
#include <queue>

using namespace std;
int answer = 0;

void dfs(int n, vector<vector<int>>& com, vector<bool>& visit)
{
    // 이미 방문했다면 검사할 필요가 없다.
    if(visit[n]) return;
    
    answer++;
    queue<int> q;
    q.push(n);
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        visit[node] = true;
        
        for(int i = 0; i < com[node].size(); i++)
        {
            // i와 node가 같은 경우는 자기 자신뿐이다.
            if(i == node) continue;
            
            if(!visit[i])
            {
                if(com[node][i] == 1) q.push(i);
            }
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    // 방문정보 n개를 false로 초기화
    vector<bool> visit(n, false);
    
    for(int i = 0; i < n; i++)
    {
        dfs(i, computers, visit);
    }
    
    
    return answer;
}