#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    // 남은 일의 작업량
    // N시간 동안 야근피로도를 최소화
    // works 남은 작업량
    // 1시간동안 1 처리
    // 남은 N 시간과 각 일에 대한 작업량에 대해 최소화한 값을 리턴
    
    priority_queue<int> worksQ(works.begin(), works.end());
    
    for(int i = 0; i < n; i++)
    {
        if(worksQ.empty())
            break;
        
        int work = worksQ.top();
        worksQ.pop();
        
        if(work == 0)
        {
            return 0;
        }
        
        work--;
        worksQ.push(work);
    }
    
    while(!worksQ.empty())
    {
        int work = worksQ.top();
        worksQ.pop();
        
        cout << work << endl;
        
        if(work == 0)
            break;
        
        answer += work * work;
        
    }
    
    return answer;
}