#include <iostream>
#define MAX 100001
#define MOD 9901
using namespace std;

int fac[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int DP[MAX]={1,3};

    for(int i=2;i<=N;i++){
       DP[i]=(DP[i-1]*2+DP[i-2])%MOD;
    }

    cout<<DP[N]<<'\n';
    return 0;
}