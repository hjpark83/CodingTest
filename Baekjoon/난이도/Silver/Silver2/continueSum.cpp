#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int A[100000];
    int B[100000];

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    B[0]=A[0];
    int result=A[0];

    for(int i=1;i<N;i++){
        B[i]=max(B[i-1]+A[i],A[i]);
        result=max(result,B[i]);
    }
    cout<<result<<'\n';
}   