#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    
    if(sticker.size() == 1)
        return sticker[0];
    // 스티커를 뜯어내어 최대값 만들기
    
    // 첫 번째 스티커를 포함시
    vector<int> dp(sticker.size(), 0);   // n개 방 만들고 0으로 초기화
    dp[0] = sticker[0];  
    dp[1] = sticker[0];  // 2번째 인덱스 무시
    
    // 14 14 19 25 25 34 34 0
    // 마지막 인덱스 전까지..
    for(int i = 2; i <sticker.size() - 1; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    }
    
    // 첫 번째 스티커를 포함하지 않는 경우
    vector<int> dp2(sticker.size(), 0);   // n개 방 만들고 0으로 초기화
    dp2[1] = sticker[1];
    
    for(int i = 2; i < sticker.size(); i++)
    {
        dp2[i] = max(dp2[i-1], dp2[i-2] + sticker[i]);
    }
    
    answer = max(dp[sticker.size()-2], dp2[sticker.size()-1]);


    return answer;
}