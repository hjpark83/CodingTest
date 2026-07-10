#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A[3];
    for(int i=0;i<3;i++){
        cin>>A[i];
    }

    sort(A,A+3);
    
    int result=0;
    if(A[0]+A[1]<=A[2]){
        result=2*(A[0]+A[1])-1;
    }else{
        result=A[0]+A[1]+A[2];
    }
    cout<<result<<'\n';
    return 0;
}