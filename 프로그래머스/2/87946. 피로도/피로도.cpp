#include <string>
#include <vector>

using namespace std;

int answer = 0;
int visited[8] = {0};

void dfs(int k, int cnt, vector<vector<int>>& dungeons){
    if(answer < cnt)
        answer = cnt;
    
    for(int i=0; i<dungeons.size(); i++){
        int min_p = dungeons[i][0];
        int consume = dungeons[i][1];
        
        if(k >= min_p && !visited[i]){
            visited[i] = true;
            dfs(k-consume, cnt+1, dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons){
    dfs(k, 0, dungeons);    
    return answer;
}