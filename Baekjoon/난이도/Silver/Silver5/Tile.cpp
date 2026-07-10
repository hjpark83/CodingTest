#include <iostream>
using namespace std;

typedef long long ll;
ll DP[81]={0};

ll Fib(ll N){
    DP[1]=4;
    DP[2]=6;
    DP[3]=10;
    DP[4]=16;
    
    for(int i=5;i<=N;i++){
        DP[i]=DP[i-1]+DP[i-2];
    }
    return DP[N];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N;
    cin>>N;

    cout<<Fib(N)<<'\n';
    return 0;
}