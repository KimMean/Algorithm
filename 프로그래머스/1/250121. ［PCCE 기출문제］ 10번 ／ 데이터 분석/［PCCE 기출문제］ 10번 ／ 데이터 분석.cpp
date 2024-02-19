#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool SortByCode(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

bool SortByDate(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

bool SortByMaximum(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

bool SortByRemain(vector<int> a, vector<int> b)
{
    return a[3] < b[3];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    for(int i = 0; i < data.size(); i++)
    {
        if(ext == "code")
        {
            if(data[i][0] < val_ext)
                answer.push_back(data[i]);
        }
        else if(ext == "date")
        {
            if(data[i][1] < val_ext)
                answer.push_back(data[i]);
        }
        else if(ext == "maximum")
        {
            if(data[i][2] < val_ext)
                answer.push_back(data[i]);
        }
        else if(ext == "remain")
        {
            if(data[i][3] < val_ext)
                answer.push_back(data[i]);
        }
    }
    
    if(sort_by == "code")
    {
        sort(answer.begin(), answer.end(), SortByCode);
    }
    else if(sort_by == "date")
    {
        sort(answer.begin(), answer.end(), SortByDate);
    }
    else if(sort_by == "maximum")
    {
        sort(answer.begin(), answer.end(), SortByMaximum);
    }
    else if(sort_by == "remain")
    {
        sort(answer.begin(), answer.end(), SortByRemain);
    }
    
    return answer;
}