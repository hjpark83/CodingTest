#include <iostream>
#define MAX 1001
using namespace std;

int N;
int A[MAX];
int DP[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    int result=0;
    for(int i=0;i<N;i++){
        DP[i]=1;
        for(int j=0;j<i;j++){
            if(A[i]<A[j]){
                DP[i]=max(DP[i],DP[j]+1);
            }
        }
        result=max(result,DP[i]);
    }
    cout<<result<<'\n';
    return 0;
}