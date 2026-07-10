/*문제 : https://www.acmicpc.net/problem/11265
  알고리즘 : 그래프, 플로이드-워셜
  티어 : Gold5
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
#define MAX 501
using namespace std;

int N,M;
int A,B,C;
vector<vector<int>> Dist(MAX,vector<int>(MAX, INF));

void FloydWarshall(){
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(Dist[i][j]>Dist[i][k]+Dist[k][j]){
                    Dist[i][j]=Dist[i][k]+Dist[k][j];
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
    Dist.resize(N+1, vector<int>(N+1,INF));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>Dist[i][j];
        }
    }

    FloydWarshall();
    for(int i=0; i<M; i++){
        cin>>A>>B>>C;
        if(Dist[A-1][B-1]<=C){
            cout<<"Enjoy other party\n";
        }else{
            cout<<"Stay here\n";
        }
    }
    return 0;
}