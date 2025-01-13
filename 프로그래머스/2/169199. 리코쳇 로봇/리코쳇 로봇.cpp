#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 100;

// 방향(북 동 남 서)
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int solution(vector<string> board) {
    queue<pair<int,int>> q;
    int visited[100][100] = {0,}; 
    
    for(int i = 0; i < board.size(); i++)
    {
        int idx = board[i].find('R');
        if(idx != string::npos)
        {
            q.push({i, idx});
            break;
        }
    }
    cout << visited[1][1] << endl;
    visited[q.front().first][q.front().second] = 1;
    
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        
        //cout << cur.first << "" << cur.second << endl;
        
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first;
            int ny = cur.second;
            
            // 벽이나 장애물을 만날 때 까지 이동
            while(true)
            {
                if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) break;  // 벽을 만난 경우
                if(board[nx][ny] == 'D') break; // 장애물을 만난 경우
                // 1칸씩 이동
                nx += dx[dir];
                ny += dy[dir];
            }
            // 벽과 장애물을 만났기 때문에 이전 좌표로 이동해야한다.
            nx -= dx[dir];
            ny -= dy[dir];
            
            // 이동한 위치가 골(G)인 경우
            if(board[nx][ny] == 'G') {
                return visited[cur.first][cur.second];
            }
            
            // 방문하지 않은 곳이라면 큐에 추가
            if(visited[nx][ny] == 0) {
                visited[nx][ny] = visited[cur.first][cur.second] + 1;
                q.push({nx, ny});
            }
            
        }
    }
    
    return -1;
}