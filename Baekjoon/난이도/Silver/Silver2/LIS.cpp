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
    
    int answer=0;
    for(int i=0;i<N;i++){
        DP[i]=1;
        for(int j=0;j<i;j++){
            if(A[j]<A[i]){
                DP[i]=max(DP[i],DP[j]+1);
            }
        }
        answer=max(answer,DP[i]);
    }
    cout<<answer<<'\n';
    return 0;
}
