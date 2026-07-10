#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int>A(N,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int target;
    cin>>target;

    int start=0, end=N-1, count=0;
    sort(A.begin(),A.end());

    while(start<end){
        if(A[start]+A[end]==target){
            count++;
            end--;
        }else if(A[start]+A[end]>target){
            end--;
        }else if(A[start]+A[end]<target){
            start++;
        }
    }
    cout<<count<<'\n';
    return 0;
}