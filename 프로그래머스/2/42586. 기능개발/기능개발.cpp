#include <string>
#include <vector>
#include <queue>

using namespace std;

// 진도 100%
// 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 배포
// 작업 진도 progresses, 개발 속도 speeds
// 각 배포마다 몇 개의 기능이 배포되는지 반환

// 작업 수 n < 100
// 작업 진도 < 100
// 작업 속도 <= 100
// 배포 1일 1회

// 7%1 == 0 딱떨
// 7%2 == 1 오바 + 1
// 앞에 있는 기능이 완료되어야함

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q; // 각 기능의 배포 날짜를 저장하는 큐

    // 각 기능의 배포 날짜 계산 및 큐에 추가
    for (int i = 0; i < progresses.size(); i++) {
        int days = (100 - progresses[i] + speeds[i] - 1) / speeds[i]; // 올림 연산
        q.push(days);
    }

    while (!q.empty()) {
        int cnt = 1;
        int front = q.front();
        q.pop();

        // 현재 기능의 배포 날짜와 같이 배포 가능한 다른 기능 확인
        while (!q.empty() && front >= q.front()) {
            cnt++;
            q.pop();
        }

        answer.push_back(cnt);
    }
    return answer;
}