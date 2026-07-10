#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;

long long gcd(long long a,long long b){
    if(b==0){
        return a;
    }else{
        if(a>b)
            return gcd(b,a%b);
        else
            return gcd(a,b%a);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    int alpha=1,beta=1;
    bool isBigger=false;
    
    cin>>N;
    vector<long> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        alpha*=A[i];
    }

    cin>>M;
    vector<long> B(M);
    for(int i=0;i<M;i++){
        cin>>B[i];
        beta*=B[i];
    }

    long long result=gcd(alpha,beta);
    if(result>INF){
        isBigger=true;
        result%=INF;
    }
    if(isBigger){
        printf("%09lld\n",result);
    }else{
        printf("%lld\n",result);
    }
    
    return 0;
}