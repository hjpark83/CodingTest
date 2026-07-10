#include <iostream>
using namespace std;

int main(void){
    int num,v;
    int count=0;

    cin>>num;
    int N[100];

    for(int i=0;i<num;i++){
        cin>>N[i];
    }
    cin>>v;
    for(int i=0;i<num;i++){
        if(N[i]==v){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}