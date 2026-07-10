#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<double> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    vector<double> Dp(N);
    
    Dp[0]=A[0];
    for (int i = 1; i < N; i++) {
        Dp[i]=max(A[i],Dp[i-1]*A[i]);
    }
    sort(Dp.begin(),Dp.end());
    
    cout<<fixed<<setprecision(3)<<Dp[N-1]<<'\n';
    return 0;
}