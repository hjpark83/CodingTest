#include <iostream>
#include <vector>
using namespace std;

long long ignition(int n){
    long long F[n+1];
    F[0]=1;

    for(int i=1;i<=n;i++){
        F[i]=0;
        for(int j=0;j<i;j++){
            F[i]+=F[j]*F[i-j-1];
        }
    }
    return F[n];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int N;
    cin>>N;
    long long result=ignition(N);
    cout<<result<<'\n';
    return 0;
}