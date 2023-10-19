#include <string>
#include <vector>
#include <queue>

using namespace std;

// bridge_length = 다리의 길이
// bridge_length = 최대 트럭 수
// bridge_length = 다리를 건너는 시간
// weight = 최대 무게
// answer = 시간초

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> que;
    
    int weightSum = 0;
    
    int i = 0;
    while(true){
    	int now_weight = truck_weights[i];
        if(i == truck_weights.size()){
            answer += bridge_length;
            break;
        }
        
        
        if(que.size() == bridge_length){
            weightSum -= que.front();
            que.pop();
        }
        
        if(weightSum + now_weight <= weight){
            weightSum += now_weight;
            que.push(now_weight);
            i++;
        }
        else que.push(0);
        
        answer++;
    }
    return answer;
}