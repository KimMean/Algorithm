#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
// 지역은 유일한 번호로 구분
// 두 지역간 통과 시간은 모두 1
// 지도 정보를 이용하여 최단 시간에 부대로 복귀
// 경로가 없어져 복귀가 불가능한 부대원도 있음
// 지역 수 n
// 왕복 길 정보 roads
// 각 부대원이 위치한 지역 sources
// 강철부대의 지역 destination
// sources의 원소 순서대로 강철부대로 복귀해야함
// 복귀 불가능시 -1리턴


vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> arrRoads(n+1);
    // 왕복 길 추가
    for(int i = 0; i < roads.size(); i++)
    {
        arrRoads[roads[i][0]].push_back(roads[i][1]);
        arrRoads[roads[i][1]].push_back(roads[i][0]);
    }
    
    vector<int> times(n+1, -1);   // -1로 초기화
    queue<int> q;
    q.push(destination);    // 출발지 설정
    times[destination] = 0;   // 거리 설정
    while(!q.empty())
    {
        int pos = q.front();
        q.pop();
        
        for(int i = 0; i < arrRoads[pos].size(); i++)
        {
            int target = arrRoads[pos][i];
            if(times[target] < 0)   // 아직 안간곳이라면
            {
                q.push(target);
                times[target] = times[pos] + 1;
            }
        }
    }
    
    for(int i = 0; i < sources.size(); i++)
    {
        answer.push_back(times[sources[i]]);
    }
    
    return answer;
}