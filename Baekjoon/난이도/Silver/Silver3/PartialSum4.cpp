#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M,N;
    cin>>M>>N;
    int S[100001]={};

    for(int i=1;i<=M;i++){
        int temp;
        cin>>temp;
        S[i]=S[i-1]+temp;
    }
    for(int i=0;i<N;i++){
        int start,end;
        cin>>start>>end;
        cout<<S[end]-S[start-1]<<'\n';
    }
    return 0;
}