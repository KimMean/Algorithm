#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clothesCount;
    for (auto item : clothes) {
        string type = item[1];
        clothesCount[type]++;
    }

    // 각 의상 종류별로 입거나 안 입는 경우를 고려하여 모든 조합 계산
    for (auto pair : clothesCount) {
        int count = pair.second;
        answer *= (count + 1); // 해당 종류의 의상을 입지 않는 경우까지 고려
    }

    // 모든 의상을 입지 않는 경우는 제외
    answer--;
    
    return answer;
}