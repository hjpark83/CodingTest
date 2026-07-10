#include <iostream>
using namespace std;

int main(void){
    int count,var;
    cin>>count;
    for(int i=0;i<count;i++){
        cin>>var;
        for(int j=0;j<var;j++){
            cout<<"=";
        }
        cout<<endl;
    }
    return 0;
}