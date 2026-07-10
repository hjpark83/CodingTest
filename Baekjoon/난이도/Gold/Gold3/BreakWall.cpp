/*
# Question: BJ 2206 (https://www.acmicpc.net/problem/2206)
# Rank: Gold3
# Algorithm: Graph, BFS
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 1001
using namespace std;

int N, M;
int Map[MAX][MAX][2];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void Input(){
    cin >> N >> M;

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            char tmp;
            cin >> tmp;
            Map[i][j][0] = tmp-'0';
        }
    }
}

int BFS(){
    queue<pair<int, pair<int,int>>> q;
    q.push({0,{0,0}});

    while (!q.empty()){
        int broken = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (x == N-1 && y == M-1)
            return Map[N-1][M-1][broken] + 1;

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (Map[nx][ny][0] == 1){
                if (!broken){
                    Map[nx][ny][broken+1] = Map[x][y][broken] + 1;
                    q.push({1, {nx, ny}});
                }
            }else if (Map[nx][ny][0] == 0){
                if (broken == 1 && Map[nx][ny][broken])
                    continue;
                Map[nx][ny][broken] = Map[x][y][broken]+1;
                q.push({broken, {nx, ny}});
            }
        }
    }
    return -1;
}

int main() {
    fastio
    Input();

    cout<<BFS()<<'\n';
    return 0;
}