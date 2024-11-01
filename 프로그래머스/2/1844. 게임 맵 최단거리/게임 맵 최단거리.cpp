#include<vector>
#include<iostream>
#include<queue>
#include<climits>

using namespace std;

int answer = -1;
// 상, 하, 좌, 우
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(vector<vector<int>>& map)
{
    vector<vector<int>> dist(map.size(), vector<int>(map[0].size(), INT_MAX));
    dist[0][0] = 0;
    
    int n = map.size();     // 행
    int m = map[0].size();  // 열
    
    queue<pair<int, int>> q;
    q.push({0, 0}); // 행, 열
    
    while(!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        
        // 좌우 상하 확인
        for(int i = 0; i < 4; i++)
        {
            int nx = current.first + dy[i];
            int ny = current.second + dx[i];
                        
            // 맵 범위 확인
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            
            // 벽인지 확인
            if(map[nx][ny] == 0)
                continue;
            
            // 더 짧은 거리인지 확인
            if(dist[nx][ny] <= dist[current.first][current.second] + 1)
                continue;
            
            // 거리 업데이트
            dist[nx][ny] = dist[current.first][current.second] + 1;
            q.push({nx, ny});
            
        }
    }
    
    if(dist[n-1][m-1] == INT_MAX)
        answer = -1;
    else
        answer = dist[n-1][m-1] + 1;
    
}

int solution(vector<vector<int>> m)
{
    bfs(m);
    
    return answer;
}