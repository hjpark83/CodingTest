#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin>>N>>K;

    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int sum=0;

    for(int i=0;i<K;i++){
        sum+=A[i];
    }
    int max_sum=sum;
    
    for(int i=K;i<N;i++){
        sum=sum-A[i-K]+A[i];
        max_sum=max(max_sum,sum);
    }
    cout<<max_sum<<'\n';
    return 0;
}