/*문제 : https://www.acmicpc.net/problem/1012
  알고리즘 : 그래프, BFS
  티어 : Silver2
*/
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

#define MAX 51

int T, N, M, K, cnt;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int Graph[MAX][MAX]={0,};
bool visited[MAX][MAX]={false};

void bfs(int x, int y){
    queue <pii> q;
    q.push(pii(x,y));
    visited[x][y]=true;

    while(!q.empty()){
        pii v=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=v.first+dx[i];
            int ny=v.second+dy[i];

			if (nx>-1 && ny>-1 && nx<M && ny<N && Graph[nx][ny]==1 && visited[nx][ny]==false){
				visited[nx][ny]=true;
				q.push(pii(nx, ny));
			}
        }
    }
}

void init(){
    cnt=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            Graph[i][j]=0;
            visited[i][j]=false;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>T;

    while(T--){
        cin>>M>>N>>K;
        
        for(int i=0;i<K;i++){
            int start,end;
            cin>>start>>end;
            Graph[start][end]=1;
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(Graph[i][j]==1 && visited[i][j]==false){
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
        init();
    }
}