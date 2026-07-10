#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int GCD(int x, int y){
    if(y==0)
        return x;
    else
        return GCD(y,x%y);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<ll> Result(N);
    
    while(N--){
        int M;
        cin>>M;

        ll sum=0;
        vector<ll> A(M);
        for(int j=0;j<M;j++){
            cin>>A[j];
        }

        for(int j=0;j<M;j++){
            for(int k=j+1;k<M;k++){
                sum+=GCD(A[j],A[k]);
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}