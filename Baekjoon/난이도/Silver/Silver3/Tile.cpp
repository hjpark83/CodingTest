#include <iostream>
#define MAX 1001
#define MOD 10007
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int DP[MAX];

    DP[0]=1;
    DP[1]=3;
    for(int i=2;i<N;i++){
        DP[i]=(DP[i-1]+DP[i-2]*2)%MOD;
    }
    cout<<DP[N-1]%MOD<<'\n';
    return 0;
}