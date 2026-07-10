/*
# Question: BJ 1981 (https://www.acmicpc.net/problem/1981)
# Rank: 
# Algorithm: 
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 100
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 987654321;

int N, maxVal, minVal;
int arr[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool inRange(int x, int y) {
    return x>=0 && x<N && y>=0 && y<N;
}

void Input() {
    maxVal = -1;
    minVal = 500;
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
            if(arr[i][j] > maxVal)
                maxVal = arr[i][j];
            if(arr[i][j] < minVal)
                minVal = arr[i][j];
        }
    }
}

bool BFS(int diff){
    queue<pii> Q;
    for(int i=minVal; i<=maxVal; i++){
        memset(visited, true, sizeof(visited));
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if(arr[j][k] >= i && arr[j][k] <= i+diff){
                    visited[j][k] = false;
                }
            }
        }
        Q.push({0, 0});
        while(!Q.empty()){
            pii cur = Q.front();
            Q.pop();
            if(visited[cur.first][cur.second])
                continue;
            visited[cur.first][cur.second] = true;
            if(cur.first == N-1 && cur.second == N-1)
                return true;
            for(int j=0; j<4; j++){
                int nx = cur.first + dx[j];
                int ny = cur.second + dy[j];
                if(inRange(nx, ny) && !visited[nx][ny]){
                    Q.push({nx, ny});
                }
            }
        }
    }
    return false;
}

int main(void){
    fastio
    Input();

    int s = 0, e = maxVal - minVal, mid;
    while(s<=e){
        mid = (s+e)/2;
        if(BFS(mid))
            e = mid - 1;
        else
            s = mid + 1;
    }
    cout<<s<<endl;
}