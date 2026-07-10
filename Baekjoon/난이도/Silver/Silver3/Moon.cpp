#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> dp(N+1,N+1);
    dp[0]=0;

    vector<int> coins={1,2,5,7};

    for(int i=1;i<=N;i++){
        for(int coin:coins){
            if(i>=coin){
                dp[i]=min(dp[i],dp[i-coin]+1);
            }
        }
    }
    cout<<dp[N]<<'\n';
    return 0;
}