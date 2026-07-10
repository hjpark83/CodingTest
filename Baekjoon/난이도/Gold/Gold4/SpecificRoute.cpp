/*
# Question: BJ 1504 (https://www.acmicpc.net/problem/1504)
# Rank: Gold4
# Algorithm: Graph, Dijkstra, Shortest Path
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 801
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int N, E, v1, v2, ans1, ans2;
vector<pii> adj[MAX];
int dist[MAX];

void Input();
int Dijkstra(int start, int end);
int FindShortestPath(int v1, int v2);

void Input(){
    cin >> N >> E;
    for (int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> v1 >> v2;
}

int Dijkstra(int start, int end){
    for(int i=1; i<=N; i++){
        dist[i] = INF;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int curDist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < curDist) 
            continue;
        for(int i = 0; i < adj[cur].size(); i++){
            int nextDist = adj[cur][i].first;
            int nextVertex = adj[cur][i].second;
            if(dist[nextVertex] > curDist + nextDist){
                dist[nextVertex] = curDist + nextDist;
                pq.push({dist[nextVertex], nextVertex});
            }
        }
    }
    return dist[end];
}

// v1, v2를 거치는 경로 중 최단 경로 찾기
int FindShortestPath(int v1, int v2){
    ans1 = INF, ans2 = INF;
    if (Dijkstra(1, v1) == INF || Dijkstra(v1, v2) == INF || Dijkstra(v2, N) == INF)
        ans1 = INF;
    else
        ans1 = Dijkstra(1, v1) + Dijkstra(v1, v2) + Dijkstra(v2, N);

    // 1-> V2 -> V1 -> N 끊기는 부분 있는지 체크
    if (Dijkstra(1, v2) == INF || Dijkstra(v2, v1) == INF || Dijkstra(v1, N) == INF)
        ans2 = INF;
    else
        ans2 = Dijkstra(1, v2) + Dijkstra(v2, v1) + Dijkstra(v1, N);

    return min(ans1, ans2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    FindShortestPath(v1, v2);

    // 정답 출력
    if (ans1 == INF && ans2 == INF)
        cout << "-1";
    else
        cout << min(ans1, ans2);
    return 0;
}