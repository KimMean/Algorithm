#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> wantMap;
    
    for(int i = 0; i < want.size(); i++)
    {
        wantMap[want[i]] = number[i];
    }
    
    unordered_map<string, int> discount_set;
    for(int i = 0; i < 9; i++)
        discount_set[discount[i]]++;
    
    for(int i = 9; i < discount.size(); i++)
    {
        discount_set[discount[i]]++;
        
        if(wantMap == discount_set) answer++;
        if(--discount_set[discount[i-9]] == 0)
            discount_set.erase(discount[i-9]);
    }
    return answer;
}