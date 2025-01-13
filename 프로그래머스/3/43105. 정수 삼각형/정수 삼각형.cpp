#include <string>
#include <vector>

using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int length = triangle.size();
    dp[0][0] = triangle[0][0];

    for(int i = 1; i < length; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0)
                dp[i][j] = dp[i-1][j];
            else if (j == i)
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
            
            dp[i][j] += triangle[i][j];
        }
    }

    for(int i = 0; i < length; i++)
    {
        if(dp[length-1][i] > answer)
            answer = dp[length-1][i];
    }

    return answer;
}