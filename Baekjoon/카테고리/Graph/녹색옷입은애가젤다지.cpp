/*
# Question: BJ 4485 (https://www.acmicpc.net/problem/4485)
# Rank: Gold4
# Algorithm: Dijkstra, Graph, Shortest Path
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 1000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//const int INF = 1e9;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    fastio
    
    int N;
    int map[126][126];
    int dist[126][126];
    int i = 1;

    while(1){
        cin >> N;
        if(N==0)
            break;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
                dist[i][j] = MAX;
            }
        }
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[0][0] = map[0][0];
        pq.push({dist[0][0], 0}); // cost, x*N+y

        while(!pq.empty()){
            int cost = pq.top().first;
            int x = pq.top().second / N;
            int y = pq.top().second % N;
            pq.pop();

            if(dist[x][y] < cost)
                continue;

            for(int dir=0; dir<4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(nx<0 || ny<0 || nx>=N || ny>=N)
                    continue;

                if(dist[nx][ny] > dist[x][y] + map[nx][ny]){
                    dist[nx][ny] = dist[x][y] + map[nx][ny];
                    pq.push({dist[nx][ny], nx*N+ny});
                }
            }
        }
        cout << "Problem " << i++ << ": " << dist[N-1][N-1] << '\n';
    }
    return 0;
}