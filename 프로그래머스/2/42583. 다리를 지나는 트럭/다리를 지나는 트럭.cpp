#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int total_weight = 0;
    int i = 0;
    queue<int> bridge;
    
    while(1){
        int n_weight = truck_weights[i];
        if(i == truck_weights.size()){
            time += bridge_length;
            break;
        }
        
        if(bridge.size() == bridge_length){
            total_weight -= bridge.front();
            bridge.pop();
        }
        
        if(total_weight + n_weight <= weight){
            total_weight += n_weight;
            bridge.push(n_weight);
            i++;
        }else{
            bridge.push(0);
        }
        time++;
    }
    
    return time;
}