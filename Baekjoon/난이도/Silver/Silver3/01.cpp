#include <iostream>
#include <vector>

#define MAX 10000001
const int MOD=15746;
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N; 

    vector<int> DP(MAX);
    DP[1]=1;
    DP[2]=2;
    for(int i=3;i<=N;i++){
        DP[i]=(DP[i-1]+DP[i-2])%MOD;
    }
    cout<<DP[N]<<'\n';
    return 0;
}