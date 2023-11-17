#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(int N, int number) {
    
     if (N == number) return 1;

    // i개의 N으로 만들 수 있는 숫자들
    vector<unordered_set<int>> DP(8);

    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        sum = sum * 10 + N;
        DP[i].insert(sum);
    }

    for (int i = 1; i < 8; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int a : DP[j]) {
                for (int b : DP[i - j - 1]) {
                    DP[i].insert(a + b);
                    DP[i].insert(a - b);
                    DP[i].insert(a * b);
                    if (b != 0)
                        DP[i].insert(a / b);
                }
            }
        }
    }

    for (int i = 0; i < 8; ++i) {
        if (DP[i].find(number) != DP[i].end()) {
            return i + 1;
        }
    }


    return -1;
}