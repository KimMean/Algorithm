#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool Comp(string a, string b)
{
    return a.length() <= b.length();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size()-1; i++)
    {
        if(phone_book[i+1].substr(0, phone_book[i].length()) == phone_book[i])
            return false;
    }
    
    return answer;
}