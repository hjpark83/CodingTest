/*문제 : https://www.acmicpc.net/problem/11049
  알고리즘 : DP
  티어 : Gold3
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
vector<vector<int>> DP(501,vector<int>(501));

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    vector<int> Matrix(N+1);

    for (int i=0;i<N;i++){
        int r,c;
        cin>>r>>c;
        Matrix[i]=r;
        if(i==N-1){
            Matrix[i+1]=c;
        }
    }
    
    for (int len=2;len<=N;len++){
        for (int i=1;i<=N-len+1;i++){
            int j=i+len-1;
            DP[i][j]=INT_MAX;

            for(int k=i;k<j;k++){
                DP[i][j]=min(DP[i][j],DP[i][k]+DP[k+1][j]+Matrix[i-1]*Matrix[k]*Matrix[j]);
            }
        }
    }
    
    cout<<DP[1][N];
    return 0;
}
