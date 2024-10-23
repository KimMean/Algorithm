#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool MatFit(vector<vector<string>>& park, int x, int y, int matSize)
{
    for(int i = x; i < x + matSize; i++)
    {
        for(int j = y; j < y + matSize; j++)
        {
            if(park[i][j] != "-1")
                return false;
        }
    }
    
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    
    sort(mats.begin(), mats.end(), greater<int>());
    
    for(int m = 0; m < mats.size(); m++)
    {
        for(int i = 0; i < park.size(); i++)
        {
            // 돗자리 크기보다 남은 크기가 작다면
            if(mats[m] > park.size() - i)
                break;

            for(int j = 0; j < park[i].size(); j++)
            {
                // 돗자리 크기보다 남은 크기가 작다면
                if(mats[m] > park[i].size() - j)
                    break;
                
                if(MatFit(park, i, j, mats[m]))
                    return mats[m];
            }
        }
    }
    
    return answer;
}