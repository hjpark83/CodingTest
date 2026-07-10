#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int index=1;
    vector<int> A(N+1,0);
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            A[j]=1-A[j];
        }
    }
    int count=0;
    for(int i=1;i<=N;i++){
        if(A[i]==1){
            count++;
        }
    }
    cout<<count<<'\n';
    return 0;
}