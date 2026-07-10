#include <string>
#include <vector>

using namespace std;

int answer = 0;
vector <int> nums;
int tgt;

void dfs(int idx, int sum){
    if(idx == nums.size()){
        if(sum == tgt){
            answer++;
        }
        return;
    }
    
    dfs(idx+1, sum+nums[idx]);
    dfs(idx+1, sum-nums[idx]);
}

int solution(vector<int> numbers, int target) {
    nums = numbers;
    tgt = target;
    
    dfs(0, 0);
    return answer;
}