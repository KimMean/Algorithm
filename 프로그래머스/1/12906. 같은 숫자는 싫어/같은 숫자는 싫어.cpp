#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int idx = 0;
    answer.push_back(arr[0]);
    for(int i = 1 ; i < arr.size(); i++)
    {
        if(answer[idx] == arr[i])
        {
            continue;
        }
        answer.push_back(arr[i]);
        idx++;
    }

    return answer;
}