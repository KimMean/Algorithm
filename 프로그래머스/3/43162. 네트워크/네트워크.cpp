#include <string>
#include <vector>

using namespace std;

bool isVisited[200]{false};

void DFS(vector<vector<int>>& coms, int cur, int n)
{
    isVisited[cur] = true;
    
    for(int i = 0; i < n; i++){
        // 아직 방문하지 않았고, 연결되어 있는 컴퓨터 번호 일 때
        if(!isVisited[i] && coms[cur][i] == 1){
            DFS(coms, i, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        if(!isVisited[i])
        {
            DFS(computers, i, n);
            answer++;
        }
    }
    return answer;
}