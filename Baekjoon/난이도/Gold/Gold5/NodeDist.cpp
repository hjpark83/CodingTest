/*문제 : https://www.acmicpc.net/problem/1240
  알고리즘 : 그래프, BFS, DFS, Tree
  티어 : Gold5
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int N, M;
vector<pair<int, int>> graph[MAX];
bool visited[MAX] = {false, };
int dist[MAX] = {0, };

void Reset(){
    for (int i=1; i<=N; i++){
        visited[i]=false;
        dist[i]=0;
    }
}

void BFS(vector<pair<int, int>> *graph, int start, int end) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int weight = graph[cur][i].second;
            if(!visited[next]) {
                visited[next] = true;
                dist[next] = dist[cur] + weight;
                q.push(next);
            }
        }
    }
    cout<<dist[end]<<"\n";
    Reset();
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i=0; i<N-1; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    for(int i=0; i<M; i++) {
        int a, b;
        cin>>a>>b;
        BFS(graph, a, b);
    }
    return 0;
}