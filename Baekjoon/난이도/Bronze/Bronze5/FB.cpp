#include <iostream>
using namespace std;

int main(void){
    int num;
    cin>>num;
    string S;
    for(int i=0;i<num;i++){
        cin>>S;
        cout<<S[0]<<S[S.length()-1]<<'\n';
    }
    return 0;
}