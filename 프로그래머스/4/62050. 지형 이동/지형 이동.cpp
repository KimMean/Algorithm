#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pos
{
    int r;
    int c;
    int heightDiff;
    bool operator < (const Pos & p) const { return heightDiff > p.heightDiff; }
};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[301][301];

bool isValid(int nr, int nc, int rows, int cols)
{
    return nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc];
}

int solution(vector<vector<int>> land, int height) {
    int totalCost = 0;
    int rows = land.size();
    int cols = land[0].size();
    
    priority_queue<Pos> pq;
    pq.push({0, 0, 0});
    
    while(!pq.empty())
    {
        Pos current = pq.top();
        pq.pop();
        
        if(visited[current.r][current.c])
            continue;
        
        totalCost += current.heightDiff;
        
        for(int i = 0; i < 4; i++)
        {
            int nr = current.r + dy[i], nc = current.c + dx[i];
            if(isValid(nr, nc, rows, cols))
            {
                int diff = abs(land[current.r][current.c] - land[nr][nc]);
                
                if(diff > height)
                    pq.push({nr, nc, diff});
                else
                    pq.push({nr, nc, 0});
            }
        }
        
        visited[current.r][current.c] = true;
    }
    return totalCost;
}