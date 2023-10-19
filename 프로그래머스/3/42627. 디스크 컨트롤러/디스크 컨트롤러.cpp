#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0; // 현재 시간
    int index = 0; // jobs 벡터의 인덱스
    int n = jobs.size();
    
    // 요청 시간이 빠른 순서대로 정렬
    sort(jobs.begin(), jobs.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    while (index < n || !pq.empty()) {
        if (index < n && time >= jobs[index][0]) {
            pq.push({jobs[index][1], jobs[index][0]});
            index++;
            continue;
        }

        if (!pq.empty()) {
            pair<int, int> current = pq.top();
            pq.pop();
            time += current.first;
            answer += time - current.second;
        } else {
            time = jobs[index][0];
        }
    }

    return answer / n;
}