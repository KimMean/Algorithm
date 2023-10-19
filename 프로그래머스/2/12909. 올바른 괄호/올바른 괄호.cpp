#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ')')
        {
            if(st.empty())
            {
                return  false;
            }
            st.pop();
        }
        else 
        {
            st.push(s[i]);
        }
    }
    
    return st.empty();
}