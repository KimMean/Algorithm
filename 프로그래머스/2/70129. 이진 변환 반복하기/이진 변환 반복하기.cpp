#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    int transforms = 0;
    int removedZeros = 0;
    
    while(s != "1")
    {
        transforms++;
        
        removedZeros += count(s.begin(), s.end(), '0');
        
        int onesCount = count(s.begin(), s.end(), '1');
        s = bitset<32>(onesCount).to_string();
        s = s.substr(s.find('1'));
    }
    
    return {transforms, removedZeros};
}