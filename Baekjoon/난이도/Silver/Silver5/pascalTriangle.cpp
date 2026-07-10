#include <iostream>
using namespace std;

long long combi(int n, int k){
    long long result=1;
    k=min(k,n-k);

    for(int i=0;i<k;i++){
        result*=(n-i);
        result/=(i+1);
    }
    return result;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;

    cout<<combi(n-1,k-1)<<'\n';
    return 0;
}