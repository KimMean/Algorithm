#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    vector<vector<int>> giftMap(friends.size(), vector<int>(friends.size()));
    vector<int> counts(friends.size());
    map<string, int> nameIdx;
    
    for(int i = 0; i < friends.size(); i++)
        nameIdx[friends[i]] = i;
    
    string from;
    string to;
    for(int i = 0; i < gifts.size(); i++)
    {
        stringstream ss(gifts[i]);
        ss >> from >> to;
        // 선물 카운트 증가
        giftMap[nameIdx[from]][nameIdx[to]]++;  
        // 선물 지수 조절
        counts[nameIdx[from]]++;    
        counts[nameIdx[to]]--;
    }
    vector<int> result(friends.size());
    for(int i = 0 ; i < friends.size()-1; i++)
    {
        for(int j = i+1 ; j < friends.size(); j++)
        {
            int fromCount = giftMap[i][j];
            int toCount = giftMap[j][i];
            
            if(fromCount > toCount)
                result[i]++;
            else if(fromCount < toCount)
                result[j]++;
            else
            {
                if(counts[i] > counts[j])
                    result[i]++;
                if(counts[i] < counts[j])
                    result[j]++;
            }
                
        }
    }
    
    for(int i = 0; i < result.size(); i++)
    {
        if(answer < result[i])
            answer = result[i];
    }
    
    
    return answer;
}