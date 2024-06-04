#include <string>
#include <vector>

using namespace std;

vector<vector<int>> map;

void dfs(int x, int y, int n, vector<int> &answer){
    int sum=0;
    
    for(int i=x; i<x+n; i++)
        for(int j=y; j<y+n; j++)
            sum+=map[i][j];
    
    if(sum==0){
        answer[0]++;
        return;
    }
    
    else if(sum==n*n){
        answer[1]++;
        return;
    }
    
    dfs(x, y, n/2, answer);
    dfs(x, y+n/2, n/2, answer);
    dfs(x+n/2, y, n/2, answer);
    dfs(x+n/2, y+n/2, n/2, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    map=arr;
    
    dfs(0, 0, arr.size(), answer);
    
    return answer;
}