/*
# Question: BJ 2638 (https://www.acmicpc.net/problem/2638)
# Rank: Gold3
# Algorithm: Implementation, Graph, Simulation, DFS, BFS
*/

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 105
using namespace std;
typedef pair<int, int> pii;

int Map[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int N, M, ans;
queue<pii> Q;

void Input(){
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>Map[i][j];
        }
    }
}

void DFS(int x, int y){
    if (Map[x][y] == 0)
        Map[x][y] = -1;
    else
        return;

    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= M)
            DFS(nx, ny);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Input();
    DFS(1, 1);
    while (true){
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= M; j++){
                if (Map[i][j] == 1){
                    int cnt = 0;
                    for (int k = 0; k < 4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (Map[nx][ny] == -1)
                            cnt++;
                    }
                    if (cnt >= 2)
                        Q.push(make_pair(i, j));
                }
            }
        }
        if (Q.empty())
            break;

        while (!Q.empty()){
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();

            Map[x][y] = -1;
            for (int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (Map[nx][ny] == 0)
                    DFS(nx, ny);
            }
        }
        ans++;
    }
    cout<<ans<<'\n';
    return 0;
}