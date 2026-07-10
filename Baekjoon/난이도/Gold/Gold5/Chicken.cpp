/*문제 : https://www.acmicpc.net/problem/21278
  알고리즘 : 그래프, 브루트포스, 최단 경로, 플로이드 와샬
  티어 : Gold5
*/
#include <iostream>
#include <vector>

#define INF 1e9
using namespace std;

int N, M;
int dp[101][101];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            if(i==j)
                dp[i][j]=0;
            else
                dp[i][j]=INF;
        }
    }
    for(int i=0;i<M;i++){
        int start, end;
        cin>>start>>end;
        dp[start][end]=1;
        dp[end][start]=1;
    }

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    int a=0, b=0, min_dist=INF;
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            int dist=0;
            for(int k=1;k<=N;k++){
                dist+=min(i==k?0:dp[i][k], j==k?0:dp[j][k]);
            }
            if(dist<min_dist){
                min_dist=dist;
                a=i, b=j;
            }
        }
    }
    cout<<a<<" "<<b<<" "<<min_dist*2;
    return 0;
}