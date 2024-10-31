#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int value = s / n;
    int remain = s % n;
    
    if(value <= 0)
    {
        answer.push_back(-1);
        return answer;
    }
    
    for(int i = 0; i < n -remain; i++)
    {
            answer.push_back(value);
    }
    for(int i = 0; i < remain; i++)
    {
            answer.push_back(value + 1);
    }
    
    
    return answer;
}