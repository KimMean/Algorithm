#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int>& numbers, int n, int sum, int target)
{
    if(n >= numbers.size())
    {
        // 마지막에 타겟넘버가 같다면 답 추가
        if(sum == target)
            answer++;
        return;
    }
    
    // + 경우
    dfs(numbers, n+1, sum + numbers[n], target);
    // - 경우
    dfs(numbers, n+1, sum - numbers[n], target);
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, 0, 0, target);
    return answer;
}