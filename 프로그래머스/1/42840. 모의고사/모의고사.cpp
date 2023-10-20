#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> f = {1, 2, 3, 4, 5};
    vector<int> s = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> t = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> score(3);
    int idxF = 0;
    int idxS = 0;
    int idxT = 0;
    
    
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == f[idxF++]) score[0]++;
        if(answers[i] == s[idxS++]) score[1]++;
        if(answers[i] == t[idxT++]) score[2]++;
        
        if(idxF == f.size()) idxF = 0;        
        if(idxS == s.size()) idxS = 0;        
        if(idxT == t.size()) idxT = 0;
    }
    
    int maxScore = *max_element(score.begin(), score.end());
    
    for(int i = 0 ; i < score.size(); i++)
    {
        if(maxScore == score[i])
            answer.push_back(i+1);
    }
    
    return answer;
}