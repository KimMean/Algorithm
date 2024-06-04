#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_set>

using namespace std;

int solution(vector<string> strs, string t)
{
    int INF = numeric_limits<int>::max();
    int n = t.length();
    vector<long long> dp(n + 1, INF);
    dp[0] = 0;
    
    unordered_set<int> sizes;
    for(const auto &s : strs)
        sizes.insert(s.length());
    
    unordered_set<string> strsSet(strs.begin(), strs.end());
    
    for(int i = 1; i <= n; i++)
    {
        for(int size : sizes)
        {
            if(i >= size && strsSet.count(t.substr(i - size, size)))
                dp[i] = min(dp[i], dp[i - size] + 1);
        }
    }
    
    return dp[n] != INF ? dp[n] : -1;
}