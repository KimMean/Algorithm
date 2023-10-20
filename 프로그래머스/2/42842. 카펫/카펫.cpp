#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int max = brown + yellow;
    
    for(int height = 3; height <= sqrt(max); height++)
    {
        if(max % height == 0)
        {
            int width = max / height;
            
            if(((width + height) * 2 - 4) == brown)
            {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    
    return answer;
}