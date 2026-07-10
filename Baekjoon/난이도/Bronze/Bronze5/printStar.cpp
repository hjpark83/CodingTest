#include <iostream>
using namespace std;

int main(void){
    int num;
    cin>>num;

    for(int i=0;i<num;i++){
        for(int j=num;j>=num-i;j--){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}