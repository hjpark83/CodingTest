#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin>>N>>K;

    vector<int> A(N,0);

    int j=0;
    for(int i=1;i<=N;i++){
        if(N%i==0){
            A[j]=i;
            j++;
        }
    }
    if(A.size()>=K){
        cout<<A[K-1]<<" ";
    }else{
        cout<<0<<endl;
    }
    return 0;
}