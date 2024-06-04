#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    
    sort(d.begin(), d.end());
    int count = 0;
    
    for(int amount : d)
    {
        if(budget < amount)
            break;
        budget -= amount;
        count++;
    }
    
    return count;
}