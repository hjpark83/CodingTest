/*
# Question: BJ 1761 (https://www.acmicpc.net/problem/1761)
# Rank: Platinum5
# Algorithm: Tree, LCA
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 40001
using namespace std;
typedef pair<int, int> pii;


int N, M;
vector<pii> adj[MAX];
bool visited[MAX];

int length[MAX][16];
int parent[MAX][16];
int depth[MAX];

int ans[10001][2];

void DFS(int start, int N){
    visited[start] = true;
    depth[start] = N;

    for(int i=0; i<adj[start].size(); i++){
        int next = adj[start][i].first;
        int cost = adj[start][i].second;

        if(!visited[next]){
            parent[next][0] = start;
            length[next][0] = cost;
            DFS(next, N+1);
        }else{
            continue;
        }
    }
}

void Connect(){
    for(int i=1; i<16; i++){
        for(int j=1; j<=N; j++){
            parent[j][i] = parent[parent[j][i-1]][i-1];
            length[j][i] = length[j][i-1] + length[parent[j][i-1]][i-1];
        }
    }
}

int LCA(int x, int y){
    if(depth[x] > depth[y]){
        swap(x, y);
    }

    int diff = depth[y] - depth[x];
    int sum = 0;

    for(int i=0; diff; i++){
        if(diff % 2){
            sum += length[y][i];
            y = parent[y][i];
        }
        diff /= 2;
    }

    if(x == y){
        return sum;
    }

    for(int i=15; i>=0; i--){
        if(parent[x][i] != parent[y][i]){
            sum += length[x][i] + length[y][i];
            x = parent[x][i];
            y = parent[y][i];
        }
    }

    sum += length[x][0] + length[y][0];
    return sum;
}

void Input() {
    cin>>N;
    for(int i=0;i<N-1;i++) {
        int s, e, d;
        cin>>s>>e>>d;
        adj[s].push_back({e, d});
        adj[e].push_back({s, d});
    }
    cin>>M;
    for(int i=0; i<M; i++) {
        cin>>ans[i][0]>>ans[i][1];
    }
}

int main() {
    fastio
    Input();

    DFS(1, 0);
    Connect();

    for(int i=0; i<M; i++){
        int x = ans[i][0];
        int y = ans[i][1];
        cout<<LCA(x, y)<<'\n';
    }
    
    return 0;
}