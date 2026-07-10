#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define MAX_NUM 1299709
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> A(MAX_NUM+1,1);
    A[0]=A[1]=0;

    vector<int> B(N);
    for(int i=0;i<N;i++){
        cin>>B[i];
    }

    vector<int> C;
    for(int i=2;i<sqrt(MAX_NUM);i++){
        if(A[i]==1){
            for(int j=i*i;j<=MAX_NUM;j+=i){
                A[j]=0;
            }
        }
    }
    for(int i=0;i<A.size();i++){
        if(A[i]==1){
            C.push_back(i);
        }
    }
    
    for(int i=0;i<N;i++){
        if(A[B[i]]==1){
            cout<<"0"<<'\n';
        }else{
            int idx=lower_bound(C.begin(),C.end(),B[i])-C.begin();
            cout<<C[idx]-C[idx-1]<<'\n';
        }
    }
}