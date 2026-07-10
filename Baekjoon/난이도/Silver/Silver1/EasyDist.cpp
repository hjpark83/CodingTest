/*
# Question: BJ 14940 (https://www.acmicpc.net/problem/14940)
# Rank: Silver1
# Algorithm: Graph, BFS
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 1001
using namespace std;

int N, M;
int Map[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void Input() {
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>Map[i][j];
        }
    }
}

void BFS(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    Map[a][b] = 0;
    visited[a][b] = true;
    dist[a][b] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M){
                if(!visited[nx][ny] && Map[nx][ny] == 1){
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

void FindStart(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(Map[i][j] == 2){
                BFS(i, j);
            }
        }
    }
}

void Print(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(dist[i][j]==0 && Map[i][j]==1){
                cout<<-1<<" ";
            }else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}

int main() {
    fastio;
    Input();
    FindStart();
    Print();
    return 0;
}