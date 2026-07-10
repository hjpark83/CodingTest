/*
# Question: BJ 1967 (https://www.acmicpc.net/problem/1967)
# Rank: Gold4
# Algorithm: Graph, BFS
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 10001
using namespace std;
typedef long long ll;
typedef pair<pair<int, int>, int> piii;

int N;
vector<piii> Node;
vector<int> dist(MAX, 0);
vector<bool> visited(MAX, false);

void Input() {
    cin>>N;
    for(int i=1; i<=N; i++){
        int parent, child, weight;
        cin>>parent>>child>>weight;
        Node.push_back({{parent, child}, weight});
    }
}

void BFS(int a){
    queue<int> q;
    q.push(a);
    visited[a] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<Node.size(); i++){
            if(Node[i].first.first == x && !visited[Node[i].first.second]){
                q.push(Node[i].first.second);
                dist[Node[i].first.second] = dist[x] + Node[i].second;
                visited[Node[i].first.second] = true;
            }
            if(Node[i].first.second == x && !visited[Node[i].first.first]){
                q.push(Node[i].first.first);
                dist[Node[i].first.first] = dist[x] + Node[i].second;
                visited[Node[i].first.first] = true;
            }
        }
    }
}

int main() {
    fastio
    Input();
    
    BFS(1);
    int maxIdx = 1;
    for(int i=2; i<=N; i++){
        if(dist[i] > dist[maxIdx]){
            maxIdx = i;
        }
    }

    fill(visited.begin(), visited.end(), false);
    fill(dist.begin(), dist.end(), 0);
    
    BFS(maxIdx);
    int ans = 0;
    for(int i=1; i<=N; i++){
        ans = max(ans, dist[i]);
    }

    cout<<ans<<'\n';
    return 0;
}