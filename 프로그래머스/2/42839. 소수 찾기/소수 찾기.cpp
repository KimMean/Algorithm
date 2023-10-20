#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>

using namespace std;

int CheckPrime(int n)
{
    if(n == 0 || n == 1) return 0;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0) return 0;
    }
    return 1;
}

int solution(string numbers) {
    int answer = 0;
    unordered_set<int> uos;
    int value;
    sort(numbers.begin(), numbers.end());
    
    do 
    {
        for(int i = 1; i <= numbers.size() ; i++)
        {
            value = stoi(numbers.substr(0, i));
            if(CheckPrime(value))
                uos.insert(value);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    
    return uos.size();
}