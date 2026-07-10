#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 101
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,num,S=0;
    cin>>N;

    vector<int> A;
    vector<int> B;

    for(int i=0;i<N;i++){
        cin>>num;
        A.push_back(num);
    }
    for(int i=0;i<N;i++){
        cin>>num;
        B.push_back(num);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());

    for(int i=0;i<N;i++){
        S+=(A[i]*B[i]);
    }
    cout<<S<<'\n';
    return 0;
}
