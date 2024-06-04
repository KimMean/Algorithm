#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int counts[100001] = {};

void updateCounts(const string &s)
{
    string numStr;
    
    for(char ch : s)
    {
        if(isdigit(ch))
            numStr += ch;
        else
        {
            if(!numStr.empty())
            {
                counts[stoi(numStr)]++;
                numStr.clear();
            }
        }
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    updateCounts(s);
    
    vector<pair<int, int>> freqPairs;
    for(int i = 0; i < 100000; i++)
    {
        if(counts[i] > 0)
            freqPairs.push_back({counts[i], i});
    }
    
    sort(freqPairs.rbegin(), freqPairs.rend());
    
    for(const auto &p : freqPairs)
        answer.push_back(p.second);
    return answer;
}