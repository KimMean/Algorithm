#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux = wallpaper.size();
    int luy = wallpaper[0].size();
    int rdx = 0, rdy = 0;
    
    for(int i = 0; i < wallpaper.size(); i++)
    {
        for(int j = 0; j < wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                if(lux > i)
                    lux = i;
                if(luy > j)
                    luy = j;
                if(rdx < i)
                    rdx = i;
                if(rdy < j)
                    rdy = j;
            }
        }
    }
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx+1);
    answer.push_back(rdy+1);
    //cout << lux << luy << rdx << rdy << endl;
    return answer;
}