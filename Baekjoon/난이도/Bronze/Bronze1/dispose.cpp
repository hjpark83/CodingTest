#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> A(N);

    while(N>1){
        for(int i=2;i<=N;i++){
            if(N%i==0){
                cout<<i<<'\n';
                N/=i;
                break;
            }
        }
    }
    return 0;
}