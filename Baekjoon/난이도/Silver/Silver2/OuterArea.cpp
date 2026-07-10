#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;

    vector<vector<int>> A(N+2,vector<int>(M+2,0));

    int TotalA=2*N*M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>A[i][j];
        }
    }
    for(int x=1;x<=N;x++){
        for(int y=1;y<=M;y++){
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(A[x][y]>A[nx][ny])
                    TotalA+=(A[x][y]-A[nx][ny]);
            }
        }
    }

    cout<<TotalA<<'\n';
    return 0;
}