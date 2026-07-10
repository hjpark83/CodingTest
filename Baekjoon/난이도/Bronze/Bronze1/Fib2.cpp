#include <iostream>
using namespace std;

long long Fib(int n){
    long long f[n+1];
    f[0]=0;
    f[1]=1;

    for(int i=2;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    long long result=Fib(N);
    cout<<result<<'\n';
    return 0;
}