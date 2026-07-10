#include <iostream>
#define MAX 10001
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int A[MAX];
    int DP[MAX];

    A[0]=0;
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    
    DP[0]=0;
    DP[1]=A[1];
    DP[2]=A[1]+A[2];
    for(int i=3;i<=N;i++){
        DP[i]=max(DP[i-3]+A[i-1]+A[i],max(DP[i-2]+A[i],DP[i-1]));
    }
    cout<<DP[N]<<'\n';
    return 0;
}