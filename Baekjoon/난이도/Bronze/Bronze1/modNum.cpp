#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> A(N,0);

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    cout<<A[0]*A[N-1]<<'\n';
    return 0;
}