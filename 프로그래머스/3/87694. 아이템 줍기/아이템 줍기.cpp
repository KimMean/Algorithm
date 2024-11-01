#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

// 좌우 상하
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int targetX;
int targetY;
int answer = INT_MAX;

void dfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int x, int y, int count)
{
    if(visited[y][x])
        return;
    
    if(map[y][x] != 1)
        return;
        
    if(x == targetX && y == targetY)
    {
        if(answer > count)
            answer = count;
        return;
    }
        
    
    visited[y][x] = true;
    
    for(int i = 0; i < 4; i++)
    {
        int nx = x - dx[i];
        int ny = y - dy[i];
        
        dfs(map, visited, nx, ny, count+1);
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    // 2배로 만들고 -1로 채운다.
    targetX = itemX * 2;
    targetY = itemY * 2;
    
    vector<vector<int>> map(102, vector<int>(102,-1));
    vector<vector<bool>> visited(102, vector<bool>(102, false));
    
    for(int i = 0; i < rectangle.size(); i++)
    {
        // 2배로 만들어야함
        int lx = rectangle[i][0] * 2;
        int ly = rectangle[i][1] * 2;
        int rx = rectangle[i][2] * 2;
        int ry = rectangle[i][3] * 2;
        
        // 왼쪽 x 부터 오른쪽 x까지
        for(int x = lx; x <= rx; x++)
        {
            // 하단 y부터 위 y까지
            for(int y = ly; y <= ry; y++)
            {
                // 이미 어떤 사각형의 내부라면 건들필요 없음
                if(map[y][x] == 0)
                    continue;
                // 외곽선은 1로, 내부는 0으로 만듬
                if(x == lx || x == rx || y == ly || y == ry)
                    map[y][x] = 1;
                else
                {
                    map[y][x] = 0;
                }
                
            }
        }
    }
    
    dfs(map, visited, characterX*2, characterY*2, 0);
    
    
    return answer / 2;
}