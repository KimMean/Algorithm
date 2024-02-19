#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    
    int successBandage = 0;
    int time = 0;
    int attackCount = 0;
    while(true)
    {
        time++;
        if(attackCount == attacks.size()) break;
        // 공격시간
        if(attacks[attackCount][0] <= time)
        {
            answer -= attacks[attackCount][1];  // 체력 감소
            attackCount++;      // 공격 카운팅
            successBandage = 0; // 공격 받아 연속 성공 초기화
            if(answer <= 0) return -1;  // 캐릭터 죽음
        }
        else    // 체력 회복 가능
        {
            successBandage++;
            answer += bandage[1];
            if(successBandage >= bandage[0])    // 연속성공
            {
                successBandage = 0;
                answer += bandage[2];
            }
            if(answer > health) // 최대체력 회복 불가
                answer = health;
        }
    }
    return answer;
}