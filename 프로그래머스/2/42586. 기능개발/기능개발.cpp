#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days_q;
    
    for(int i=0; i<progresses.size(); ++i){
        int days = (100-progresses[i]+speeds[i]-1) / speeds[i];
        days_q.push(days);
    }
    
    while(!days_q.empty()){
        int cur_days = days_q.front(); // 기준일
        days_q.pop();
        
        int cnt = 1;
        // queue 맨 앞의 값이 현재일보다 작거나 같으면 함께 배포됨
        while(!days_q.empty() && days_q.front() <= cur_days){
            cnt++;
            days_q.pop();
        }
        answer.push_back(cnt);
    }
    
    return answer;
}