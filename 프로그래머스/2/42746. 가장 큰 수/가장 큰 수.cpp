#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool Comp(const string &lhs, const string &rhs)
{
    return (lhs + rhs) > (rhs + lhs);
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> strings;
    
    for (auto elem : numbers) {
        strings.push_back(to_string(elem));
    }
    sort(strings.begin(), strings.end(), Comp);
    
    for (auto elem : strings)
        answer += elem;
    
    if (answer[0] == '0')
        answer = '0';

    return answer;
}