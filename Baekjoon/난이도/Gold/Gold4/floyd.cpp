/*문제 : https://www.acmicpc.net/problem/11404
  알고리즘 : 그래프, 플로이드-워셜
  티어 : Gold4
*/

#include <iostream>
#define INF 100000001
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    long mdistance[101][101];

    cin>>N>>M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j){
                mdistance[i][j]=0;
            }else{
                mdistance[i][j]=INF;
            }
        }
    }
    for(int i=0;i<M;i++){
        int s,e,v;
        cin>>s>>e>>v;
        if(mdistance[s][e]>v){
            mdistance[s][e]=v;
        }
    }
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(mdistance[i][j]>mdistance[i][k]+mdistance[k][j]){
                    mdistance[i][j]=mdistance[i][k]+mdistance[k][j];
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(mdistance[i][j]==INF){
                cout<<"0 ";
            }else{
                cout<<mdistance[i][j]<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}