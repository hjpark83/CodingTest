/*문제 : https://www.acmicpc.net/problem/1613
  알고리즘 : 그래프 이론, 최단 경로, 플로이드-워셜
  티어 : Gold3
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin>>N>>K;
    vector<vector<int>> v(N+1,vector<int>(N+1,0));

    for(int i=1;i<=K;i++){
        int s,e;
        cin>>s>>e;
        v[s][e]=-1;
        v[e][s]=1;
    }

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(v[i][j]==0){
                    if(v[i][k]==1 && v[k][j]==1){
                        v[i][j]=1;
                    }
                    else if(v[i][k]==-1 && v[k][j]==-1){
                        v[i][j]=-1;
                    }
                }
            }
        }
    }
    int S;
    cin>>S;

    for(int i=1;i<=S;i++){
        int a,b;
        cin>>a>>b;
        cout<<v[a][b]<<"\n";
    }
    return 0;
}