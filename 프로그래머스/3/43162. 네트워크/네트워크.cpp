#include <string>
#include <vector>
#include <queue>

using namespace std;
int answer = 0;

void dfs(int n, vector<vector<int>>& computers, vector<bool>& visited)
{
    if(visited[n])
        return;
    
    answer++;
    // q 넣고
    queue<int> q;
    q.push(n);
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        if(visited[node])
            continue;
        
        visited[node] = true;
        
        // 한 행 돌면서 연결된 노드 푸시
        for(int i = 0; i < computers.size(); i++)
        {
            if(node == i)
                continue;
            
            if(computers[node][i] == 1)
                q.push(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; i++)
        dfs(i, computers, visited);
    return answer;
}