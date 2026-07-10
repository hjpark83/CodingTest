#include <iostream>
using namespace std;

int main(void){
    int K,N,M;
    cin>>K>>N>>M;
    int money=K*N-M;
    if(money<0){
        money=0;
    }
    cout<<money<<endl;
    return 0;
}