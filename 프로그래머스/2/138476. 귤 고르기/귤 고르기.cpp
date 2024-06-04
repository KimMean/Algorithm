#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    
    unordered_map<int, int> counter;
    
    for(int i = 0; i < tangerine.size(); i++)
        counter[tangerine[i]]++;
    
    vector<int> sorted_counts;
    for(const auto &kv : counter)
        sorted_counts.push_back(kv.second);
    sort(sorted_counts.rbegin(), sorted_counts.rend());
    
    int numType = 0;
    int countSum = 0;
    
    for(int count : sorted_counts)
    {
        countSum += count;
        numType++;
        if(countSum >= k)
            break;
    
    }
        
    return numType;
}