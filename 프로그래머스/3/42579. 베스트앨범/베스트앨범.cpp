#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool ComparePopular(pair<string,int> a, pair<string,int> b)
{
    return a.second > b.second;
}
bool ComparePlay(pair<int,int> a, pair<int,int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> type;
    unordered_map<string, vector<pair<int, int>>> play;
    
    for(int i = 0; i < genres.size(); i++)
    {
        type[genres[i]] += plays[i];
        play[genres[i]].push_back(make_pair(i, plays[i]));
    }
    
    vector<pair<string,int>> typeVec(type.begin(), type.end());
    sort(typeVec.begin(), typeVec.end(), ComparePopular);
    
    for(auto name : typeVec)
    {
        sort(play[name.first].begin(), play[name.first].end(), ComparePlay);
        for(int i = 0; i < 2; i++)
        {
            if(play[name.first].size() == i) continue;
            answer.push_back(play[name.first][i].first);
        }
    }
    
    return answer;
}