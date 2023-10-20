#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isTransformable(const string& word1, const string& word2) {
    int diffCount = 0;
    for (int i = 0; i < word1.length(); i++) {
        if (word1[i] != word2[i]) {
            diffCount++;
            if (diffCount > 1) {
                return false;
            }
        }
    }
    return diffCount == 1;
}

int solution(string begin, string target, vector<string> words) {
     if (find(words.begin(), words.end(), target) == words.end()) {
        return 0; // target이 words에 없으면 변환 불가능
    }

    int answer = 0;
    queue<pair<string, int>> q;
    q.push({begin, 0});

    while (!q.empty()) {
        string currentWord = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (currentWord == target) {
            answer = steps;
            break;
        }

        for (const string& word : words) {
            if (isTransformable(currentWord, word)) {
                q.push({word, steps + 1});
            }
        }
    }
    return answer;
}