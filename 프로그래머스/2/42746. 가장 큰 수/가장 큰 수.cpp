#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool Comp(string &a, string &b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> strings;
    for (int i=0; i<numbers.size(); i++) {
        strings.push_back(to_string(numbers[i]));
    }
    sort(strings.begin(), strings.end(), Comp);
    
    for (int i=0; i<strings.size(); i++)
        answer += strings[i];
    
    if (answer[0] == '0')
        answer = '0';

    
    return answer;
}