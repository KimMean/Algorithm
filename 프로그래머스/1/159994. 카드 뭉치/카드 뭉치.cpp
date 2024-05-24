#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    int c1 = 0;
    int c2 = 0;
    int g = 0;
    
    for(int i = 0; i < goal.size(); i++)
    {
        bool check = false;
        if(c1 < cards1.size() && goal[i] == cards1[c1])
            c1++;
        else if (c2 < cards2.size() && goal[i] == cards2[c2])
            c2++;
        else
            return "No";
    }
    
    return answer;
}