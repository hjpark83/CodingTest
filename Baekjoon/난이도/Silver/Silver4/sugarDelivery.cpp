#include <iostream>
using namespace std;

namespace WEIGHT{
    enum{
        op1=3, op2=5
    };
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int count=0; 
    while(N>=0){ 
        if(N%WEIGHT::op2==0){
            count+=(N/WEIGHT::op2);
            cout<<count<<'\n';
            return 0;
        }
        N-=3;
        count++;
    }
    cout<<"-1"<<'\n';
}