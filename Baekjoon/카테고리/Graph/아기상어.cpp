/*
# Question: BJ 16236 (https://www.acmicpc.net/problem/16236)
# Rank: Gold 3
# Algorithm: Graph, Implementation, Simulation, BFS
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 1000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//const int INF = 1e9;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    fastio
    
    int N;
    cin >> N;

    int pos_x, pos_y;
    vector<vector<int>> map(N, vector<int>(N, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j]==9){
                pos_x = i;
                pos_y = j;
            }
        }
    }
    
    int shark_size = 2, count = 0, time = 0;
    map[pos_x][pos_y] = 0;
    
    while (true) {
        vector<vector<int>> dist(N, vector<int>(N, -1));
        queue<pii> Q;

        Q.push({pos_x, pos_y});
        dist[pos_x][pos_y] = 0;

        while (!Q.empty()) {
            pii cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (dist[nx][ny] != -1 || map[nx][ny] > shark_size) continue;

                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }

        int cur_x = -1, cur_y = -1, min_dist = MAX;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] != 0 && map[i][j] < shark_size && dist[i][j] != -1) {
                    if (dist[i][j] < min_dist) {
                        min_dist = dist[i][j];
                        cur_x = i;
                        cur_y = j;
                    }
                }
            }
        }

        if (cur_x == -1 && cur_y == -1) break;

        time += min_dist;
        pos_x = cur_x;
        pos_y = cur_y;
        map[cur_x][cur_y] = 0;
        count++;

        if (count == shark_size) {
            shark_size++;
            count = 0;
        }
    }
    cout << time << "\n";

    return 0;
}