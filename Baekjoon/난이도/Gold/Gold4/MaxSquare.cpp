/*문제 : https://www.acmicpc.net/problem/1915
  알고리즘 : DP
  티어 : Gold4
*/
#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1001
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    string num;
    cin>>N>>M;

    int G[MAX][MAX];
    int DP[MAX][MAX]={0,};

    for(int i=0;i<N;i++){
        cin>>num;
        for(int j=0;j<=num.size();j++){
            G[i][j]=num[j]-'0';
        }
    }

    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            DP[i][j]=G[i][j];
            if(G[i][j]==1 && i!=0 && j!=0){
                DP[i][j]=min(DP[i-1][j-1],min(DP[i-1][j],DP[i][j-1]))+1;
            }
            ans=max(ans,DP[i][j]);
        }
    }
    cout<<ans*ans<<'\n';
    return 0;
}