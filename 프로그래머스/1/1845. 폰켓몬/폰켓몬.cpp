#include <vector>
using namespace std;

int typeArr[200000] = {0};

int solution(vector<int> nums)
{
    // n 마리 중 n / 2 마리 가짐
    // 같은 종류는 카운팅하지 않음
    
    int answer = 0;
    int getNum = nums.size() / 2;
    
    
    for(int i = 0; i < nums.size(); i++)
    {
        typeArr[nums[i]]++;
    }
    
    for(int i = 0 ; i < 200000; i++)
    {
        if(answer >= getNum)
            break;
        if(typeArr[i] > 0)
        {
            answer++;
        }
        
    }
    
    
    return answer;
}