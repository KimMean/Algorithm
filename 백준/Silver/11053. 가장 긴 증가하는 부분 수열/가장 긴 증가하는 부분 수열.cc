#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    int arr[1000];
    int dp[1000];
    
    cin >> N;
    for(int i = 0; i < N; i++) 
        cin >> arr[i];
    
    for(int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    sort(dp, dp+N);
    cout << dp[N-1];
}