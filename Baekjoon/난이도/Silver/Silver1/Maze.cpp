#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int N,M;
int Dist[101][101];
char Map[101][101];
int visited[101][101];

void BFS(int start_x, int start_y){
    visited[start_x][start_y]=1;

    queue<pair<int,int>> Q;
    Q.push(make_pair(start_x,start_y));

    while(!Q.empty()){
        int x=Q.front().first;
        int y=Q.front().second;

        Q.pop();

        for(int i=0;i<4;i++){
            int next_x=x+dx[i];
            int next_y=y+dy[i];
            if(next_x>=0 && next_x<N && next_y>=0 && next_y<M){
                if(Map[next_x][next_y]=='1' && visited[next_x][next_y]==0){
                    Dist[next_x][next_y]=Dist[x][y]+1;
                    visited[next_x][next_y]=1;
                    Q.push(make_pair(next_x,next_y));
                }
            }
        }
        
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i=0;i<N;i++){
        cin>>Map[i];
    }
    BFS(0,0);
    cout<<Dist[N-1][M-1]+1<<'\n';
    return 0;
}