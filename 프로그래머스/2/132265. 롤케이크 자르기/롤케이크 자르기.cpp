#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int, int> topping_cnt;
    unordered_set<int> half_topping;
    
    for(auto top : topping)
    {
        if(topping_cnt.find(top) == topping_cnt.end())
            topping_cnt[top] = 1;
        else
            topping_cnt[top]++;
    }
    
    for(int i = 0; i < topping.size(); i++)
    {
        half_topping.insert(topping[i]);
        topping_cnt[topping[i]]--;
        
        if(topping_cnt[topping[i]] == 0)
            topping_cnt.erase(topping[i]);
        
        if(topping_cnt.size() == half_topping.size())
            answer++;
    }
    
    return answer;
}