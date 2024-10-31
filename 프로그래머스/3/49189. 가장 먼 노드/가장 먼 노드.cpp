#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    // n+1인 이유?
    vector<vector<int>> graph(n+1);
    
    // 양방향 간선
    for(int i = 0; i < edge.size(); i++)
    {
        int from = edge[i][0];
        int to = edge[i][1];
        
        graph[from].push_back(to);
        graph[to].push_back(from);
        
        // graph[1] = 2, 3
        // graph[2] = 1, 3, 4, 5
    }
    
    // -1로 초기화
    vector<int> dist(n+1, -1);
    queue<int> q;
    
    // 1부터 시작
    dist[1] = 0;
    q.push(1);
    
    // q가 빌때까지
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        
        // 다음 목적지
        for(int next : graph[current])
        {
            if(dist[next] == -1)
            {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }
    
    int far = *max_element(dist.begin(), dist.end());
    
    for(int d : dist)
    {
        if(d == far)
            answer++;
    }
    
    return answer;
}