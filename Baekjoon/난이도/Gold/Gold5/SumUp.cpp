/*문제 : https://www.acmicpc.net/problem/2225
  알고리즘 : 수학, DP
  티어 : Gold5
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD=1000000000;

ll DP[201][201]={0};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N,K;
    cin>>N>>K;

    DP[0][0]=1;
    for(int i=0;i<=N;i++){
        DP[1][i]=1;
    }
    for(int i=2;i<=K;i++){
        for(int j=0;j<=N;j++){
            for(int k=0;k<=j;k++){
                DP[i][j]+=DP[i-1][k];
            }
            DP[i][j]%=MOD;
        }
    }
    cout<<DP[K][N]<<'\n';
    return 0;
}