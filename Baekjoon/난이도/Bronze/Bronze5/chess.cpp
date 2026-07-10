#include <iostream>
#include <vector>
using namespace std;

namespace CHESS{
    enum{
        King=1, Queen=1, Look=2, Vishop=2, Knight=2, Pawn=8
    };
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> A(6);
    vector<int> B(6);

    for(int i=0;i<6;i++){
        cin>>A[i];
    }
    
    B[0]=CHESS::King-A[0];
    B[1]=CHESS::Queen-A[1];
    B[2]=CHESS::Look-A[2];
    B[3]=CHESS::Vishop-A[3];
    B[4]=CHESS::Knight-A[4];
    B[5]=CHESS::Pawn-A[5];
    
    for(int i=0;i<6;i++){
        cout<<B[i]<<" ";
    }
    return 0;
}