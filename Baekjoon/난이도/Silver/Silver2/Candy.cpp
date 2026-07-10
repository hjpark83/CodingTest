#include <iostream>
#include <vector>

#define MAX 1001
using namespace std;

int N,M;
vector<vector<int>> Candy;
vector<vector<int>> DP;

void init(){
    Candy.resize(N+1, vector<int>(M+1,0));
    DP.resize(N+1, vector<int>(M+1,0));
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>Candy[i][j];
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    init();
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            DP[i][j]=Candy[i][j]+max(max(DP[i-1][j],DP[i][j-1]),DP[i-1][j-1]);
        }
    }
    int result=0;
    for(int j=1;j<=M;j++){
        result=max(result,DP[N][j]);
    }

    cout<<result<<'\n';
    return 0;
}