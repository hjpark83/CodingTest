#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
typedef pair<pair<int,int>,int> ppi;

int M,N,H;
int Graph[MAX][MAX][MAX];
queue<ppi> Q;

int dx[6]={0,0,1,-1,0,0};
int dy[6]={1,-1,0,0,0,0};
int dz[6]={0,0,0,0,1,-1};

void BFS(){
    while(!Q.empty()){
        int x=Q.front().first.first;
        int y=Q.front().first.second;
        int z=Q.front().second;

        Q.pop();
        for(int i=0;i<6;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nz=z+dz[i];

            if(nx>=0 && ny>=0 && nz>=0 && nx<N && ny<M && nz<H){
                if(Graph[nx][ny][nz]==0){
                    Graph[nx][ny][nz]=Graph[x][y][z]+1;
                    Q.push(make_pair(make_pair(nx,ny),nz));
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>M>>N>>H;
    for(int k=0;k<H;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>Graph[i][j][k];
                if(Graph[i][j][k]==1)
                    Q.push(make_pair(make_pair(i,j),k));
            }
        }
    }
    BFS();

    int result=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<H;k++){
                if(Graph[i][j][k]==0){
                    cout<<-1<<'\n';
                    return 0;
                }else{
                    result=max(result,Graph[i][j][k]);
                }
            }
        }
    }
    cout<<result-1<<'\n';
    return 0;
}