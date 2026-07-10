#include <iostream>
using namespace std;

int dp[11]={1,2,4};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int N;
    for(int i=3;i<11;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    cin>>N;

    while(N--){
        int t;
        cin>>t;
        cout<<dp[t-1]<<'\n';
    }
    return 0;
}