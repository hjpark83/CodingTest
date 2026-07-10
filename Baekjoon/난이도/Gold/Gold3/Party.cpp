/*
# Question: BJ 1238 (https://www.acmicpc.net/problem/1238)
# Rank: Gold3
# Algorithm: Graph, Dijkstra, Shortest path
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 1001
#define INF 1e9

using namespace std;
typedef pair<int, int> pii;

int N, M, X;
vector<pii> v[2][MAX];
int dist[2][MAX], Result[MAX];

void Input() {
    cin>>N>>M>>X;
    
    for(int i=0; i<M; i++){
        int S, E, T;
        cin>>S>>E>>T;
        v[0][S].push_back({E, T});
        v[1][E].push_back({S, T});
    }
}

void Dijkstra(int start, int X){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, X});
    dist[start][X] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[start][cur] < cost) 
            continue;
        
        int size = static_cast<int>(v[start][cur].size());
        for(int i=0; i<size; i++){
            int nextNode = v[start][cur][i].first;
            int nextCost = v[start][cur][i].second + cost;
            if(dist[start][nextNode] > nextCost){
                pq.push({nextCost, nextNode});
                dist[start][nextNode] = nextCost;
            }
        }
    }
}

int main() {
    fastio
    Input();
    
    int answer = -1;

    fill(dist[0], dist[1] + MAX, INF);
    Dijkstra(1, X);
    Dijkstra(0, X);

    for(int i=1; i<=N; i++){
        answer = max(answer, dist[0][i] + dist[1][i]);
    }
    cout<<answer<<'\n';
    return 0;
}