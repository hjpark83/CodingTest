#include <iostream>
#define MAX 100001
using namespace std;

int DP[2][MAX];
int T, N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>T;

    while(T--){
        cin>>N;
        for(int i=0;i<2;i++){
            for(int j=2;j<=N+1;j++){
                cin>>DP[i][j];
            }
        }

        for(int i=2;i<=N+1;i++){
            DP[0][i]+=max(DP[1][i-1],DP[1][i-2]);
            DP[1][i]+=max(DP[0][i-1],DP[0][i-2]);
        }
        cout<<max(DP[0][N+1], DP[1][N+1])<<'\n';
    }
    return 0;
}
