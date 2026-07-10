#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

int Graph[MAX][MAX];
queue<pii> Q;
int N,M;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void BFS(){
    while(!Q.empty()){
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && ny>=0 && nx<N && ny<M){
                if(Graph[nx][ny]==0){
                    Graph[nx][ny]=Graph[x][y]+1;
                    Q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>M>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>Graph[i][j];

            if(Graph[i][j]==1){
                Q.push({i,j});
            }
        }
    }
    BFS();

    int result=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Graph[i][j]==0){
                cout<<-1<<'\n';
                return 0;
            }else{
                result=max(Graph[i][j],result);
            } 
        }
    }
    cout<<result-1<<'\n';
}