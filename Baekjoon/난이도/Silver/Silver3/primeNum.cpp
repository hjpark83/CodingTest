#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M,N;
    cin>>M>>N;

    vector<int> A(N+1,1);
    A[0]=A[1]=0;

    for(int i=2;i<=sqrt(N);i++){
        for(int j=i*i;j<=N;j+=i){
            A[j]=0;
        }
    }
    for(int i=M;i<=N;i++){
        if(A[i]==1){
            cout<<i<<'\n';
        }
    }
    return 0;
}