#include <iostream>
#include <vector>

 #define MAX 10000
 using namespace std;

 int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    vector<vector<int>> Trg(N,vector<int>(N,0));

    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            cin>>Trg[i][j];
        }
    }

    vector<vector<int>> DP(N,vector<int>(N,0));
    DP[0][0]=Trg[0][0];
    for(int i=1;i<N;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                DP[i][j]+=(DP[i-1][j]+Trg[i][j]);
            }else if(j==i){
                DP[i][j]+=(DP[i-1][j-1]+Trg[i][j]);
            }else{
                DP[i][j]+=(Trg[i][j]+max(DP[i-1][j-1],DP[i-1][j]));
            }
        }
    }
    int result=0;
    for(int i=0;i<N;i++){
        result=max(result,DP[N-1][i]);
    }
    cout<<result<<'\n';
    return 0;
 }