#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long left = 0;
    long right = times[times.size() - 1] * (long)n; // 가장 긴 시간을 기준으로 계산
    
    while(left <= right)
    {
        long mid = (left + right) / 2;
        long complete = 0;
        for(int i = 0; i < times.size(); i++)
        {
            complete += mid / times[i];
            //cout << "Mid : " << mid << "Time : " << times[i] << "Com : " << complete << endl;
        }
        if(complete < n)    // 해당 시간에는 모든 사람이 검사받을 수 없다.
            left = mid + 1;
        else                // 모두 검사받았으나, 더 최솟값이 있을 수 있다.
        {
            right = mid - 1;
            answer = mid;
        }
    }
    
    return answer;
}