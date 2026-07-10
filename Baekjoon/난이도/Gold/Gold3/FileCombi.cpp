/*문제 : https://www.acmicpc.net/problem/11066
  알고리즘 : DP
  티어 : Gold3
*/

#include <iostream>
#include <algorithm>
#define MAX 501
#define INF 1e9
using namespace std;

int T, K;
int DP[501][501];
int C[501];
int sum[501];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>T;
    while(T--){
        cin>>K;
        for(int i=1;i<=K;i++){
            cin>>C[i];
            sum[i]=sum[i-1]+C[i];
        }
        for(int i=1;i<K;i++){
            for(int j=1;j<=K-i;j++){
                DP[j][i+j]=INF;

                for(int k=j;k<i+j;k++){
                    DP[j][i+j]=min(DP[j][i+j],DP[j][k]+DP[k+1][i+j]+sum[i+j]-sum[j-1]);
                }
            }
        }
        cout<<DP[1][K]<<'\n';
    }
    return 0;
}