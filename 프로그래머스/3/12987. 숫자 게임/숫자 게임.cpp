#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    // 2*N명 중 N명씩 두 팀
    // 자연수 하나 받고 누가 더 큰지 비교
    // 승리 1점 동점 x
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int index = 0;
    for(int i = 0; i < B.size(); i++)
    {
        if(A[index] < B[i])
        {
            index++;
            answer++;
        }
    }
    
    return answer;
}