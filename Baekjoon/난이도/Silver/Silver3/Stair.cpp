#include <iostream>
#define MAX 301
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int A[MAX];
    int DP[MAX];

    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    DP[1]=A[1];
    DP[2]=A[1]+A[2];
    DP[3]=max(A[1]+A[3],A[2]+A[3]);

    for(int i=4;i<=N;i++){
        DP[i]=max(DP[i-2]+A[i],DP[i-3]+A[i-1]+A[i]);
    }
    cout<<DP[N]<<'\n';
    return 0;
}