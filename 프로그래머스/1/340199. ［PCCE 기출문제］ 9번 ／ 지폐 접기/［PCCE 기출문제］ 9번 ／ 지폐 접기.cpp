#include <string>
#include <vector>

using namespace std;

bool InWallet(int walletW, int walletH, int billW, int billH)
{
    return (walletW >= billW && walletH >= billH);
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while(true)
    {
        // 들어가는 경우
        if(InWallet(wallet[0], wallet[1], bill[0], bill[1]) || 
            InWallet(wallet[0], wallet[1], bill[1], bill[0]))
            break;
        
        if(bill[0] > bill[1])
        {
            bill[0] /= 2;
        }
        else
        {
            bill[1] /= 2;
        }
        
        answer++;
        
    }
        
    return answer;
}