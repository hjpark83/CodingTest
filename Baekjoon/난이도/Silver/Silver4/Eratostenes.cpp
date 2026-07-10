#include <iostream>
#include <vector>
#include <cmath>

#define MAX_NUM 1000
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin>>N>>K;

    vector<int> A(N+1,1);
    A[0]=A[1]=0;

    int cnt=0;
    for(int i=2;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            if(A[j]!=0){
                A[j]=0;
                cnt++;
                if(cnt==K){
                    cout<<j<<'\n';
                    return 0;
                }
            }
        }
    }
}