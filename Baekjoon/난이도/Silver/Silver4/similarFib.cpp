#include <iostream>
using namespace std;

long long Fib(int n){
    long long F[200];
    F[1]=F[2]=F[3]=1;

    for(int i=4;i<=n;i++){
        F[i]=F[i-1]+F[i-3];
    }
    return F[n];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int N;
    cin>>N;

    long long result=Fib(N);
    cout<<result<<'\n';

    return 0;
}