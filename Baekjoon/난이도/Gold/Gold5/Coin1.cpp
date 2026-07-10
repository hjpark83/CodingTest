/*문제 : https://www.acmicpc.net/problem/2293
  알고리즘 : DP
  티어 : Gold5
*/

#include <iostream>
#include <vector>

#define MAX 10001
using namespace std;

int N,K;
int DP[MAX];
vector<int> Coin;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K;
    Coin.resize(N+1);

    for(int i=1;i<=N;i++){
        cin>>Coin[i];
    }
    DP[0]=1;

    for(int i=1;i<=N;i++){
        for(int j=Coin[i];j<=K;j++){
            DP[j]+=DP[j-Coin[i]];
        }
    }
    cout<<DP[K]<<'\n';
    return 0;
}