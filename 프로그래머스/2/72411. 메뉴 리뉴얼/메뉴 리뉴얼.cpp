#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> Combi;

void Combination(string src, string dst, int depth)
{
    if(dst.size() == depth)
        Combi[dst]++;
    else
        for(int i = 0; i < src.size(); i++)
            Combination(src.substr(i+1), dst+src[i], depth);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(string &order : orders)
        sort(order.begin(), order.end());
    
    for(int len : course)
    {
        for(string order : orders)
            Combination(order, "", len);
    
        int maxOrder = 0;
        for(auto it : Combi)
            maxOrder = max(maxOrder, it.second);
        
        for(auto it : Combi)
            if(maxOrder >= 2 && it.second == maxOrder)
                answer.push_back(it.first);

        Combi.clear();
    }
        
    sort(answer.begin(), answer.end());
    
    return answer;
}