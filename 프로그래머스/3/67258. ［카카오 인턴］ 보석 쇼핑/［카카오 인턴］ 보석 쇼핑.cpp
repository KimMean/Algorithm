#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    int shortDist = gems.size();
    
    set<string> gemSet(gems.begin(), gems.end());
    map<string,int> gemMap;
    
    int firstIndex = 0;
    int lastIndex =0;
    
    int index = 0;
    int count = 0;
    for(int i = 0; i < gems.size(); i++)
    {
        if(gemMap[gems[i]] == 0)
            count++;
        
        gemMap[gems[i]]++;
        if(count == gemSet.size())
        {
            for(int j = index; j <= i; j++)
            {
                gemMap[gems[j]]--;
                
                // 모두 포함하는 시작점
                
                if(gemMap[gems[j]] == 0)
                {
                    count--;
                    index = j+1;
                    // 짧은 구간
                    if(shortDist > i - j)
                    {
                        shortDist = i-j;
                        firstIndex = j;
                        lastIndex = i;
                    }
                    break;
                }
            }
        }
    }
    
    answer.push_back(firstIndex+1);
    answer.push_back(lastIndex+1);
    
    return answer;
}